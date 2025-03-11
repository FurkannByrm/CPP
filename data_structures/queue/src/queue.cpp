#include <iostream>
#include <chrono>
#include <vector>



enum class LedMode : uint16_t {
  OFF = 0x0, // 000
  GREEN = 0x1, // 100 
  BLUE = 0x2 , // 010 
  RED = 0x4, // 001 
  BOUNCING_GREEN = 0x3, // 110
  BOUNCING_BLUE = 0x5, // 101 
  BOUNCING_RED = 0x6, // 011
  CLUB_EFFECT = 0x7 // 111 
};

void send_data(uint32_t x){

    ++x;
    std::cout<<"new "<<x<<" is sending"<<"\n";

}


int main()
{

std::vector<uint16_t> led = {
                                
                                0x1,
                                0x0,
                                0x2,
                                0x0,
                                0x3

                            };


    for(auto&i : led){        
        

    }





    return 0;
}