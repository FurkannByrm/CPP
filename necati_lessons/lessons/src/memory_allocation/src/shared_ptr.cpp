#include <iostream>
#include <memory>


class A {
    public:
        A() {
            std::cout << "A Constructor" << std::endl;
        }

        ~A() {
            std::cout << "A Destructor" << std::endl;
        }
};

int main() {

    // std::shared_ptr<A> ptr = std::make_shared<A>();
    // std::cout << "Ref count of ptr(Before): " << ptr.use_count() << std::endl;
    // {
    //     std::shared_ptr<A> ptr2 = ptr;
    //     std::cout << "Ref count of ptr(Inside): " << ptr.use_count() << std::endl;
    // }
    // std::cout << "Ref count of ptr(After): " << ptr.use_count() << std::endl;
std::shared_ptr<int> ptr = std::make_shared<int>(42);
std::shared_ptr<int> ptr2 = ptr;
*ptr = 4;

std::cout << *ptr << std::endl;
std::cout << *ptr2 << std::endl;

}