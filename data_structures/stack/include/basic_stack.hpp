#pragma once

#include <iostream>
#include <bits/stdc++.h>



class Stack{


    public:

    inline static constexpr int MAX = 22222;
    int a[MAX];
    Stack();
    bool push( int x );
    int pop();
    int peek();
    bool isEmpty();

    private:
    int top;
};


