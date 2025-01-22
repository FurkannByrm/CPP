#include <boost/asio.hpp>
#include <iostream>
#include <string>




int main(){

    try
    {
        boost::asio::io_context io;
        boost::asio::serial_port serial(io, "/dev/ttyUSB0");
        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

        std::string message = "hello";
        boost::asio::write(serial,boost::asio::buffer(message));
        std::cout<<"message sent.";

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
return 0;


}