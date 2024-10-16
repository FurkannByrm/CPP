/*
Named Constructor Idiom

Bazı class lar bazı nedenlerle obje oluşturmak için client kodları
ctor fonksiyon olarak çağırması yerine ctor private yapıyor böylece
class ctor u private olduğu için client kodlar tarafından doğrudan
çağırılamıyor. Bunun yerine class ın public bölümüne bir class object
oluşturmak amaçlı factory function koyuyorlar.
kullanım nedeni nesne oluşumunu tek bir nooktaya çekmek ve bazen tüm
nesneleri dinanmik ömürlü olarak oluşturma mecburiyetine getirmek function
overloading i mümkün kılmak
*/
#include <iostream>

class Myclass{

    public:

    int x;
    static Myclass createObject(int x){ //client kodlar bu fonksiyonu doğrudan
    //çağırmazlar mecburen nesne yaratmak için createObject() fonksiyonunu çağıracaklar.
        std::cout<<"factory funtion called"<<std::endl;
        return  Myclass{x};
    }


    private:
    Myclass(int x)
    {
        std::cout<<"ctor : "<<this<<std::endl;
    }

};

    class Complex{

        public:

        static Complex createCartesian(double r, double i, int o){
            return Complex(r,i,o);
        }
        static Complex createPolar(double distance, double angle){

            return  Complex(distance,angle);
        }

        private:

        Complex(double r, double i, int o);
        Complex(double distance, double angle);
    };

int main()
{
    auto m = Myclass::createObject(12);
    m.x = 4;
    //bu fonksiyon çağrıldığında sınıfın private bölümüne erişilebiliyor
    //private ctor u çağrılabiliyor. nesne oluşturmanın tek yolu bu fonksiyonu
    //çağırmak olur.

    auto c1 = Complex::createCartesian(1.2, 2.3,3);
    auto c2 = Complex::createPolar(2.3,4.5);






    return 0;
}



/*
class ın member functionları için redecleration söz konusu değildir.
SCOPE LEAKAGE:
bir identifier kullanılan scope alanı dışında da kullannılma ihtimali varsa
bu durum gecerli olur.
*/
int foo(int m);
void func(){

    int mx = foo(3);
    if(mx>10)
    {
        //
        foo(mx);
    }
// mx burada da kullanılır, ama if blogunda tanımlanmış olsaydı mx
// o zaman undecleared identifier olmuş olacaktı
    mx =3;
}


/*
RANGE BASED FOR LOOP

3 ayrı döngü yapısı vardır

for (T x: vec)
for (T &x: vec)
for (T &&x: vec)

genelde T type yerine auto yazılır.

1. Döngü yapısı
int main()
{
int a[] = {1,3,4,5,6,77,8};
for(auto x: a){
std::cout<<x<<" ";
 x+=100;
//x in türü containerlarda tutulan öğenin türü.
burada kopyalama vardır döngünün her türünde
kaptaki öğe sizin yerel değişkeninize döngünün
gövdesinde tanımlanan yerel bir değişkene kopyalanır
}

2. Döngü yapısı
int main()
{
int a[]{1,3,4,5,6,7,8};
for(auto &x: a)
{
std::cout<<x<<" ";
x+=100;
}
//artık döngünün her türünde x dizideki öğenin kendisine
 bir referans x i kullandığımızda dizideki öğeyi kullanmış
 oluyorum const olmadığından da değişim olduğunda ve
 yapısındaki öğe değişir.
 okuma amaçlı dolaşmak istiyorsam const ref ile tanımlanır
 for(const auto &x: a)
 {
 std::cout<<x<<" ";
 }
}
}
*/

/*
DİNAMİK ÖMÜRLÜ NESNE

Ben istediğim zaman hayatını başlatıyorum, ben istediğim
zaman hayatını bitiriyorum.
Dinamik ömürlü nesneler C++ da new operatörü ile hayata
getiriliyorlar, hayata gelen nesnenin hayatını bitirmek
için delete.

new T       -> delete p
new T[]     -> delete p[]
new (expr)T
new (nothrow)

-hayata kaç tane nesne geleceği bilgisinin runtime da da
belli olması.
-farklı sayıda nesnelerin oluşturduğu bir topluluğun aynı
kaynağı paylaşması

KURAL:dinamik ömürlü nesneye ihtiyacım yoksa asla oluşturmayın
maliyeti fazla olduğu için

bunları kullanmak yerine smart pointer kullanacağız

*/
