#include <iostream>
#include <vector>   

void func1(const std::vector<int> &vec) {
    for( auto &v : vec){
        std::cout << v << std::endl;
    }
}

void func2(const std::vector<int> &vec) {
    for( auto &v : vec){
        std::cout << v << std::endl;
    }
}


int main() {


    func1({1,2,3,4,5});
    func2({6,7,8,9,10});    


    return 0;
}