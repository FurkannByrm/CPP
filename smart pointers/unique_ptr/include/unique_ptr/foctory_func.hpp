#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Product {
    public: 
    virtual void use() = 0;
    virtual ~Product() = default;
};
class ConcreteProductA : public Product {
    public:
    void use()override;  
};
class ConcreteProductB : public Product {
    public:
    void use()override;
};