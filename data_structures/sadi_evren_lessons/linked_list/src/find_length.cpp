#include "find_length.hpp"


Node::Node(int new_data) : data{new_data}, next{nullptr} {}


int countNodes(Node* head){


    int count = 0;

    Node* curr = head;

    while(curr)
    {

        count++;
        curr = curr->next;

    }

    return count;

}

int main()
{   

Node* head = new Node(1);
head->next = new Node(4);
head->next->next = new Node(3);
head->next->next->next = new Node(2);
head->next->next->next->next = new Node(4);

std::cout<<"count of nodes is "<<countNodes(head);

    return 0;
}