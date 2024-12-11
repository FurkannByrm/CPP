
#include "basic_stack.hpp"

Stack::Stack() : top{1}
{};



bool Stack::push(int x)
{
    if(top > (MAX - 1))
    {
        std::cout<<"stack overflow"<<std::endl;
        return false;
    }
    else{
        a[++top]= x;
        std::cout<<x<<" pushed into stack"<<std::endl;
        return true;
    }
}

int Stack::pop(){

if(top < 0){
std::cout<<"stack underflow"<<std::endl;
    return 0;
}

else{
    int x = a[top--];
    return x;
}


}

int Stack::peek()
{

if(top<0){
    std::cout<<"Stack is Empty";
    return 0;
}
else{
    int x = a[top];
    return x;
}

}

bool Stack::isEmpty()
{

    return (top < 0);

}



int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout<<s.pop()<< " Popped from stack"<<std::endl;

    std::cout<<"Elements present in stack : ";

    // while(!s.isEmpty()){

    //     std::cout<<s.peek()<<std::endl;
    //     s.pop();
    // }


    return 0;
}