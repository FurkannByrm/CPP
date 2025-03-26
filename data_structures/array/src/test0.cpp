#include <iostream>
#include <vector>
#include <memory>
#include <stack>

struct test0
{
    int start;
    std::shared_ptr<test0> ptr;
};

void iter(std::shared_ptr<test0>& iter, std::vector<int>& v){
    while(iter->ptr != nullptr)
    {   
        v.push_back(iter->start);
        iter = iter->ptr;
    }
    v.push_back(iter->start);
}

int main(){

    std::vector<int> vec;
    auto ptr = std::make_shared<test0>();
    ptr->start = 1;
    ptr->ptr = std::make_shared<test0>();
    ptr->ptr->start = 2;
    ptr->ptr->ptr = std::make_shared<test0>();
    ptr->ptr->ptr->start = 3;
    ptr->ptr->ptr->ptr = std::make_shared<test0>();
    ptr->ptr->ptr->ptr->start = 4;  
    ptr->ptr->ptr->ptr->ptr = nullptr;

    iter(ptr, vec);

    // for (int&i  : vec)
    // {
    //     std::cout << i << std::endl;
    // }
    
    // for (size_t i = 0; i <vec.size(); i++)
    // {
        
    //     std::cout << vec.at(i) << std::endl;
    // }
    
    // std::vector<int>::iterator it = vec.begin();
    // while (it != vec.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }

    std::stack<int> s;
    for ( std::vector<int>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        s.push(*it);
    }


    while (!s.empty())
    {
        std::cout<<s.top()<<std::endl;  
        s.pop();

    }
    
    

    return 0;
}