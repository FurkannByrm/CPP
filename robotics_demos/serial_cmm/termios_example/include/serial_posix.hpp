#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdexcept>


class SerialPort{


    public:

    SerialPort(const std::string& portname, int speed);
    ~SerialPort();

    std::string readSerial(size_t size);
    void writeSerial(const std::string& data);

    private:
    int fd; 
};

