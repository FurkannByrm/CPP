#include <iostream>

class Ctor{
  public:

  Ctor() : x(0) {
         std::cout << "Default constructor called" << std::endl;
     }
  explicit Ctor(int x){
      std::cout<<"parametreli ctor cagrildi: "<<std::endl;
  }
  void func(Ctor x);

  ~Ctor()
  {
      std::cout<<"destructor cagrildi : "<<this<<std::endl;
  }

  private:
  int x;

};


class CreateObject{

    public:
    CreateObject(const std::string& serialDev);
    private:
    int a;
};


class DefaultCtor{

  public:
  DefaultCtor(int param);
  private:
  CreateObject object; //= CreateObject("/ttyUSB0"); //CreateObject object("/ttyUSB0") not use
  int deneme;
  // parametre gecmek icin, baska bir class dan bile olsa constructor initializer list de verilmeli


};

