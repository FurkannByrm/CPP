#include "pimple_idiom/car.hpp"
#include "pimple_idiom/carImpl.hpp"

Car::Car() : pimpl(std::make_unique<CarImpl>()){
    pimpl->func();
}
Car::~Car() = default;

int main(){
    Car mycls;
    return 0;   
}