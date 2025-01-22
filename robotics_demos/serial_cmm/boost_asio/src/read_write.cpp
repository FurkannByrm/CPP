#include <boost/asio.hpp>
#include <iostream>
#include <thread>


void read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred, char* buffer)
{

if(!ec){
    std::cout<< "okunan veri :" << std::string(buffer, bytes_transferred)<<"\n";
}
else{
    std::cerr<<"hata "<<ec.message()<<"\n";
}

}


int main(){
 try {
        boost::asio::io_context io;
        boost::asio::serial_port serial(io, "/dev/ttyUSB0");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));


        char buffer[256];
        serial.async_read_some(boost::asio::buffer(buffer, sizeof(buffer)),
                               std::bind(read_handler, std::placeholders::_1, std::placeholders::_2, buffer));

            // Async işlemleri yürütmek için bir thread başlat
        std::thread t([&io]() { io.run(); });

        // Veriyi göndermek için
        std::string message = "Test Mesajı\n";
        boost::asio::write(serial, boost::asio::buffer(message));

        t.join(); // Async işlemleri bekle
    } catch (const std::exception& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    return 0;
}