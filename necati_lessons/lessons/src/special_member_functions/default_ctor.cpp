#include <iostream>

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


class Ctor{
  public:

  Ctor() : x(0) {
         std::cout << "Default constructor called" << std::endl;
     }
  explicit Ctor(int x){
      std::cout<<"parametreli ctor cagrıldı: "<<std::endl;
  }
  void func(Ctor x);

  ~Ctor()
  {
      std::cout<<"destructor cagrıldı : "<<this<<std::endl;
  }

  private:
  int x;

};


int main()
{
    double m;
    Ctor m1;
   // m1.func(m); //ERROR : clang: No viable conversion from 'double' to 'Ctor'
   Ctor m2(3);

    return  0;
}
