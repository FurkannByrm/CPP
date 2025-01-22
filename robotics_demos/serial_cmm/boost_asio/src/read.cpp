#include <boost/asio.hpp>
#include <iostream>
#include <string>



int main()
{

    try{

        boost::asio::io_context io;
        boost::asio::serial_port serial(io, "/dev/ttyUSB0");


        serial.set_option(boost::asio::serial_port_base::baud_rate(115200));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));


        char buffer[256];
        size_t bytes_read = boost::asio::read(serial,boost::asio::buffer(buffer,sizeof(buffer)));

        std::cout<<"reading data :";
        for(size_t i; i<bytes_read; ++i){
            std::cout<<buffer[i];
        }
        std::cout<<"\n";

    } catch(const std::exception& e){
            std::cerr<< " error: "<<e.what()<<"\n";

        }


    return 0;
}