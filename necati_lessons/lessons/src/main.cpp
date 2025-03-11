#include <iostream>
#include <memory>


std::shared_ptr<int> x = std::make_shared<int>(0);
void func(){

    *x = 6;
}



int main(){

auto l = []{
    std::cout<<"hello";
};


l();

return 0;
}