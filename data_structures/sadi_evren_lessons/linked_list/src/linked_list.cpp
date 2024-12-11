#include <iostream>
#include <memory>

struct Node{
    int number;
    std::unique_ptr<Node> next;
};



int main()
{
    std::unique_ptr<Node> root = std::make_unique<Node>();
    root->number = 6;
    root->next = nullptr;

    std::cout<<root->number<<std::endl;

    return 0;

}