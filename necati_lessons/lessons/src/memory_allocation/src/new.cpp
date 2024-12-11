#include <iostream>



struct Node
{
    int x;
};

int main()
{

    Node * ptr = new Node();
    ptr->x=10;

    std::cout<<ptr->x<<std::endl;

    delete ptr;

    return 0;
}