#include <iostream>
#include <memory>


struct Node
{
   int x;
};




int main()
{

std::shared_ptr<Node> ptr = std::make_shared<Node>();
ptr->x =10;
std::cout<<ptr->x<<std::endl;
std::shared_ptr<Node> ptr1 = std::make_shared<Node>();
ptr1 = ptr;//referance
ptr1->x =20;
std::cout<<ptr->x<<std::endl;
    return 0;
}