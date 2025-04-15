#pragma once
#include <iostream>
#include <memory>



// #include "class1.hpp"
// #include "class2.hpp"
// #include "class3.hpp"

// class Myclass{
    
//     public:

//     void func()const{
//         A.func();
//         B.func();
//         C.func();
//     }

//     private:
//         Class1 A;
//         Class2 B;
//         Class3 C;
// };

    class Myclass {
    
        public:
        Myclass() = default;
        void func();
        private:
        struct Pimple; // incomplete type
        std::unique_ptr<Pimple> mp;
    
    };   