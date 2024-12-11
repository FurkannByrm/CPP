#include <iostream>
#include <memory>


struct Node{

    int x;

};

int main(){

std::unique_ptr<Node> ptr = std::make_unique<Node>();
ptr->x = 10;

std::unique_ptr<Node> ptr1 =std::move(ptr);
std::unique_ptr<Node> ptr2(new Node());

ptr2->x =20;

std::cout<<ptr1->x<<std::endl;
std::cout<<ptr2->x<<std::endl;






    return 0;
}