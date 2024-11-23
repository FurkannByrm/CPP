#include "default_ctor.hpp"

/*
class Ctor{
  public:
  Ctor(); //1 user declared
  Ctor(){}; //2 user declared
  Ctor() = default; //3 user declared(default)
  Ctor() = delete; //4 user declared(delete)
};

1) de default constructor declearation var ama kod dosyasında ayrıldığı için bir definition yok.
2) de sınıfın default ctor u sınıfın define ı içinde inline olarak tanımlanmış.
3) de sınıfın default ctor u default edilmiş, Ancak = default ifadesi ile, özel olarak derleyicinin default ctor u
   oluşturmasını zorlamış olursunuz. Örneğin, başka bir ctor tanımlanmış olsa bile yine de default ctor kullanmak
   istediğinizde bu kullanışlıdır. ctor define edilmezse compiler a bırakılır.
*/

CreateObject::CreateObject(const std::string& serialDev)
{
     std::cout<<" Error "<<errno<<" from open: "<<serialDev.c_str()<<std::endl;

}

DefaultCtor::DefaultCtor(int param) : deneme{5}, object("/ttyUSB1")//priority is in the initializer list
{

  std::cout<<"default constructor cagrildi"<<std::endl;

}



int main()
{

    DefaultCtor creator{4};//creator(4), creator = 4 maybe 
  //   double m;
  //   Ctor m1;
  //  // m1.func(m); //ERROR : clang: No viable conversion from 'double' to 'Ctor'
  //  Ctor m2(3);

    return  0;
}
