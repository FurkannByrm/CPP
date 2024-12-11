#include <memory>
#include <iostream>

struct Node{
    int number;
    std::unique_ptr<Node> next;
};

void print(const std::unique_ptr<Node>& r)
{
    const Node * current = r.get();
    while(current){

        std::cout<<current->number<<std::endl;
        current = current->next.get();
    }
}

void add(const std::unique_ptr<Node>& r, int value ){

    Node * current = r.get();
    while (current->next)
    {     
        current = current->next.get();
    }
        current->next = std::make_unique<Node>();
        current->next->number =value;    
}

int main(){


    std::unique_ptr<Node> root = std::make_unique<Node>();
    root->number = 12;
    add(root, 20);
    add(root, 30);

    std::cout << "Linked List: ";
    print(root);  


    return 0;
}