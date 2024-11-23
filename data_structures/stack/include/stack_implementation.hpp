#pragma once

#include <iostream>
#include <bits/stdc++.h>



class Stack{


    public:

    inline static constexpr int MAX = 222;
    int a[MAX];
    int top;
    Stack(int m);
    bool push( int x );
    int pop();
    int peek();
    bool isEmpty();
    private:
   

};
