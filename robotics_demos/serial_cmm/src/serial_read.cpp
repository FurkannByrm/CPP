#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
    const char *port_name = "/dev/ttyUSB0"; // Seri port adı
    int serial_port = open(port_name, O_RDWR);

    if (serial_port < 0) {
        std::cerr << "Seri port açılamadı!" << std::endl;
        return 1;
    }

    // Seri port ayarlarını yapılandırma
    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0) {
        std::cerr << "Seri port ayarları okunamadı!" << std::endl;
        close(serial_port);
        return 1;
    }

    // Baud hızı ayarları
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // 8N1 modu (8 bit veri, parite yok, 1 dur bit)
    tty.c_cflag &= ~PARENB; // Parite bitini kapat
    tty.c_cflag &= ~CSTOPB; // Tek dur bit
    tty.c_cflag &= ~CSIZE;  // Veri bitlerini temizle
    tty.c_cflag |= CS8;     // 8 bit veri

    // Diğer ayarlar
    tty.c_cflag |= CREAD | CLOCAL; // Veri okuma ve yerel bağlantı modu
    tty.c_lflag &= ~ICANON;        // Kanonik mod
    tty.c_lflag &= ~ECHO;          // Eko devre dışı
    tty.c_lflag &= ~ECHOE;         // Eko silme devre dışı
    tty.c_lflag &= ~ISIG;          // Sinyal işleme devre dışı
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Yazılım akış kontrolü kapalı
    tty.c_oflag &= ~OPOST;         // Çıkış işleme kapalı

    // Ayarları uygulayın
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        std::cerr << "Seri port ayarları uygulanamadı!" << std::endl;
        close(serial_port);
        return 1;
    }

    // Seri porttan veri okuma
    char buffer[256];
    while (true) {
        int n = read(serial_port, &buffer, sizeof(buffer));
        if (n < 0) {
            std::cerr << "Veri okunamadı!" << std::endl;
            break;
        } else if (n == 0) {
            std::cout << "Bekleniyor..." << std::endl;
        } else {
            std::cout << "Gelen veri: " << std::string(buffer, n) << std::endl;
        }
    }

    // Seri portu kapatma
    close(serial_port);
    return 0;
}
