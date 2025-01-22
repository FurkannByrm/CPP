/*
18.ders 

Icsel Turler(nesned types)
type members
member types

siniflar 3 e ayriliyor : 
1. data members
2. member functions
3. member types

cpp de class icinde bir tur bildiirmi hatta tanimi yapilabilyor

class Myclass{

    class Data {
    };

    enum class Calor{blue, red, green};
    typedef int world;
    using iptr = int*;
};

oncelikle nesned type in sinif olmasi icin kurallar:

access control ve definition

(onemi standart kutupnhane cok sayida nesned type barindiriyor, kendi siniflarimiz icin de nesned type olusturabilir)
sinifin member i olduklarinda erisim kontrolune tabidir,


class Myclass{

public:

class Data{

};
};

int main(){

//Data mydata; gecersiz
Myclass::Data mydata;

}


bir nesnned typen client code lar tarafinda kullanilabilmesi icin sinifin public elemani olmasi gerekiyor.
sinifin adi ile nitelenmesi gerekiyor.


class Myclass{
private:
//Data mdata;//hata cunku derleyici bu ifadeye gelene kadarki yere bakar

    class Data{
    //...
    };
Data mdata; // gecerli olur
};





*/