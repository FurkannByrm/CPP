#include <concepts>
#include <iostream>

/*
kopyalayıcı constructor
compiler tarafından yazılan copy constructor;
a)sınıfın non-static public member function u dur.
b)inline olarak tanımlanmıştır,
c)şu imzaya sahiptir: Myclass(const Myclass &r);
buyuk coğunlukla yazımı compiler a verilir.
*/


class CopyClass{

    public:

    CopyClass(int x);
    CopyClass(){
        std::cout<<"CopyClass def ctor this = "<<this<<std::endl;
    }

    ~CopyClass(){
        std::cout<<"CopyClass class destructor this = "<<this<<std::endl;
    }

    CopyClass(const CopyClass &other){
        std::cout<<"CopyClass copy ctor "<<this<<std::endl;
        std::cout<<"&other : "<<&other<<std::endl;
    }


};

int main(){

    CopyClass m1;//default ctor hayata gelir
    std::cout<<"&m1 : "<<&m1<<std::endl;
    CopyClass m2 = m1; //m2 için ctor cağrılacak ve m1 ctor a argüman olarak gönderilecek
    std::cout<<"&m2 : "<<&m2<<std::endl;

    return 0;

}
