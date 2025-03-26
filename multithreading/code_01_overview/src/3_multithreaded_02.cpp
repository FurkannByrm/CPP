#include <iostream>
#include  <thread>
#include <chrono>


void func1(){
    for(int i = 0 ; i<100; ++i){
        std::cout<<"A"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));


    }}

void func2(){

    for(int i = 0; i<100; ++i){
        std::cout<<"B"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}

int main(){

    std::thread worker1(func1);
    std::thread worker2(func2);

    worker1.join();
    worker2.join();

    return 0;

}