#include "serial_posix.hpp"
#include <vector>

SerialPort::SerialPort(const std::string& portname, int speed)
    : fd{open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC)} {
 
    if (fd < 0) {
        throw std::runtime_error("Error opening " + portname + ": " + strerror(errno));
    }

    termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        throw std::runtime_error("Error from tcgetattr: " + std::string(strerror(errno)));
    }

    cfsetospeed(&tty, speed);
    cfsetispeed(&tty, speed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;  // 8-bit characters
    tty.c_iflag &= ~IGNBRK;  // disable break processing
    tty.c_lflag = 0;  // no signaling chars, no echo, no canonical processing
    tty.c_oflag = 0;  // no remapping, no delays
    tty.c_cc[VMIN] = 0;  // read doesn't block
    tty.c_cc[VTIME] = 5;  // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);  // disable XON/XOFF flow control
    tty.c_cflag |= (CLOCAL | CREAD);  // enable reading, ignore modem control lines
    tty.c_cflag &= ~(PARENB | PARODD);  // no parity
    tty.c_cflag &= ~CSTOPB;  // one stop bit
    tty.c_cflag &= ~CRTSCTS;  // disable RTS/CTS flow control

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        throw std::runtime_error("Error from tcsetattr: " + std::string(strerror(errno)));
    }
}

SerialPort::~SerialPort() {
    if (fd >= 0) {
        close(fd);
    }
}

void SerialPort::writeSerial(const std::string& data) {
    if (write(fd, data.c_str(), data.size()) < 0) {
        throw std::runtime_error("Error writing to serial port: " + std::string(strerror(errno)));
    }
}

std::string SerialPort::readSerial(size_t size) {
    std::vector<char> buffer(size);
    int n = read(fd, buffer.data(), size);
    if (n < 0) {
        throw std::runtime_error("Error reading from serial port: " + std::string(strerror(errno)));
    }
    return std::string(buffer.begin(), buffer.begin() + n);
}

int main() {
    try {
        SerialPort serial("/dev/ttyUSB0", B9600); // Seri portu açar ve yapılandırır
        serial.writeSerial("Hello, Serial Port!"); // Veri yazar
        std::string data = serial.readSerial(100); // Veri okur
        std::cout << "Received: " << data << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
