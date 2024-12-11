#pragma once
#include <iostream>


class Static{

    public:
    Static() = default;
    static int x; //static member data decleration
    static Static y; //class type static data member
    static void fun(){
    // z=10; clang: Invalid use of member 'z' in static member function
    // this->z = 10; durumu söz konusuydu. ama o gizli object burada yok
    }

    int mx;
    static void foo(Static &r){
        r.mx = 11; //parametreye gelen object in erişimi ile sağlanır.
    }
    void func()const{

         x= 3;//const this in const u dur, syntax error olmaz
    }

    //static int my = 3; ERROR clang: Non-const static data member must be initialized out of line
    static inline int mz = 5; // but inline keyword give permission (c++17) for header only library

    private:
    int z;

};
