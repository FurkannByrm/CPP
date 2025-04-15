#include "unique_ptr/foctory_func.hpp"

void ConcreteProductA::use(){
    std::cout << "ConcreteProductA constructor"<<"\n";
}
void ConcreteProductB::use(){
    std::cout<<"ConcreteProductB constructor"<<"\n";
}

std::unique_ptr<Product> createProduct(const std::string_view& type)
{
    if (type == "A") {
        return std::make_unique<ConcreteProductA>();
    } else if (type == "B") {
        return std::make_unique<ConcreteProductB>();
    }
    return nullptr;
} 


int main(){

    auto productA = createProduct("A");
    auto productB = createProduct("B");
    
    if (productA) productA->use();
    if (productB) productB->use();


    return 0;
}