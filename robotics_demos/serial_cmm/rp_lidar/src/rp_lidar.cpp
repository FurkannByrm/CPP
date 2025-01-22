#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace boost::asio;

int main() {
    try {
        // Boost.Asio nesneleri
        io_service io;
        serial_port serial(io, "/dev/ttyUSB0");

        // Seri port ayarları
        serial.set_option(serial_port_base::baud_rate(115200));
        serial.set_option(serial_port_base::character_size(8));
        serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
        serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        serial.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));

        std::cout << "Seri port ayarlandı: /dev/ttyUSB0" << std::endl;

        // Tarama başlatma komutu
        std::vector<unsigned char> start_scan_command = {0xA5, 0x20};
        write(serial, buffer(start_scan_command));
        std::cout << "Tarama başlatma komutu gönderildi." << std::endl;

        // Yanıt başlığını oku
        std::vector<unsigned char> header(7);
        size_t bytes_read = read(serial, buffer(header));
        if (bytes_read == 7 && header[0] == 0xA5 && header[1] == 0x5A) {
            std::cout << "Tarama başlatma yanıtı alındı." << std::endl;
        } else {
            std::cerr << "Yanıt alınamadı veya beklenen formatta değil!" << std::endl;
            for (unsigned char byte : header) {
                std::cout << "0x" << std::hex << (int)byte << " ";
            }
            std::cout << std::endl;
            return 1;
        }

        // Veri okuma döngüsü
        std::vector<unsigned char> data(5);
        while (true) {
            read(serial, buffer(data));
            unsigned char sync_quality = data[0];
            unsigned char angle_lsb = data[1];
            unsigned char angle_msb = data[2];
            unsigned char distance_lsb = data[3];
            unsigned char distance_msb = data[4];

            // Açı ve mesafe hesaplama
            float angle = ((angle_msb << 8) | angle_lsb) / 64.0f;
            float distance = ((distance_msb << 8) | distance_lsb) / 4.0f;

            // Sonuçları ekrana yazdır
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Açı: " << angle << "° "
                      << "Mesafe: " << distance << " mm" << std::endl;

            // Cihazdan gelen verilerin sıklığına göre bekleme süresi ayarlayın
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    } catch (std::exception &e) {
        std::cerr << "Hata: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
