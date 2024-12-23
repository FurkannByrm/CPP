#pragma once
class Complex{

    public:
static Complex createCartesian(double r, double i, double o){

    return Complex{r,i,o};
}

static Complex createPolar(double linear, double angular){

    return Complex{linear,angular};
}
    private: 
    Complex(double r, double i, double o){}
    Complex(double distance, double angle){}
   
};

