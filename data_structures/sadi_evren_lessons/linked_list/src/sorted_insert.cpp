#include <iostream>
#include <memory>


struct Node{

    int number;
    std::unique_ptr<Node> next;
};

void print(const std::unique_ptr<Node>& r){

    const Node * iter = r.get();
    while (iter)
    {
        std::cout<<iter->number<<std::endl;
        iter = iter->next.get();
    }

}
    
void addSorted(std::unique_ptr<Node>& root, int value) {
    auto newNode = std::make_unique<Node>();
    newNode->number = value;

    if (!root || value < root->number) {
        newNode->next = std::move(root);
        root = std::move(newNode);
        return;
    }

    Node* current = root.get();
    while (current->next && current->next->number < value) {
        current = current->next.get();
    }
    newNode->next = std::move(current->next);
    current->next = std::move(newNode);
}

int main() {
    std::unique_ptr<Node> root = nullptr;

    addSorted(root, 30);
    addSorted(root, 10);
    addSorted(root, 20);

    std::cout << "Sorted Linked List: ";
    print(root);  // 10 20 30

    return 0;
}