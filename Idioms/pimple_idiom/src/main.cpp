 #include <pimple_idiom/main.hpp>

#include "pimple_idiom/class1.hpp"
#include "pimple_idiom/class2.hpp"
#include "pimple_idiom/class3.hpp"


struct Myclass::Pimple{
   Class1 A;
   Class2 B;
   Class3 C;
};

void Myclass::func(){
      mp->A.func();
      mp->B.func();
      mp->C.func();
}


 int main()
 {
      Myclass X;
      X.func();


    return 0;
 }