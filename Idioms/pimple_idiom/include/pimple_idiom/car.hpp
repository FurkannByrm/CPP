#include <memory>
#include <iostream>


class CarImpl;

class Car{


    public:
    Car();
    ~Car();
    void start() { std::cout << "Car started" << std::endl; }
    private:
    std::unique_ptr<CarImpl> pimpl;

};