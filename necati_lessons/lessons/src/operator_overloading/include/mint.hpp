//15.ders son kisim
#ifndef MINT_INCLUDED
#define MINT_INCLUDED

#include <iosfwd> // <iostream> kullanmak yerine bunu eger forward decleration yetiyorsa
// iosfwd hpp i include edin
//incoplete type yetiyorsa asla ilgili sinifin baslik dosyasini include etmemeliyiz

class Mint{

    int mval{};
public:

    Mint() = default;
    explicit Mint(int val) : mval{val} {}//kume parantezi kullanmak zorunda degilizi uniform initializer kullandik cpp11 de geldi 
    //

Mint& operator+=(Mint other){
    mval += other.mval;
    return *this;
}

Mint& operator-=(Mint other){
    mval += other.mval;
    return *this;
}

// compiler in fonksiyon bildiriminde kullanilabilmesi icin bilmesi lazim
// ya forward decleration inin bilmesi lazim ya incomplete type, yada complete type olmasi lazim 
friend std::ostream &operator<<(std::ostream &os, Mint val);// global oldugu icin hpp de yapamam one def rule ihlal ederim. 
//birinci secenek inline yaparak hpp de tanimlamak
// ikinci secenek bu fonksiyonu decleration hpp de olacak, cpp file da define edecegiz     
//global fonksiyonlar sinifin private bolumune erismezler
//global bir fonksiyona veya bir baska sinifin uye fonksiyonuna kendi sinifimizin private bolumune erisim hakki verecegiz.
//bunu friend ile yapariz
// friend bool operator<(const Mint)
friend std::istream &operator>>(std::istream &is, Mint &m);


friend bool operator<(const Mint &x, const Mint &y)
{

    return x.mval < y.mval;


}

friend bool operator==(const Mint &x, const Mint &y)
{
    return x.mval == y.mval;
}

// static Mint Random();

};

inline bool operator>(const Mint &x, const Mint &y){
    return y<x;
}
inline bool operator>=(const Mint &x, const Mint &y){
    return !(x<y);
}
inline bool operator<=(const Mint &x, const Mint &y){
    return !(y<x);
}
inline bool operator!=(const Mint &x, const Mint &y){
    return !(x==y);
}

inline Mint operator+(Mint x, Mint y)
{
    return x+=y;
}

inline Mint operator-(Mint x, Mint y)
{
    return x-=y;
}





#endif // MINT_INCLUDED