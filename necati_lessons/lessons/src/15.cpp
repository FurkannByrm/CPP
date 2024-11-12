/*
OPERATOR OVERLOADING(OPERATOR YÜKLEMESİ)

bir sınıf nesnesi bir operatorun operandı olmuş, derleyici dilin kurallarına dayanıp 
bu ifadeyi bir fonkksiyona yapılan cağrıya dönüştürüyor. Biz bir donksiyonu ismiyle cağırmak yerine 
bir nesneyi bir operatorun operandı yapıp cağırıyoruz.

runtime da ek maliyet var mı ? kullanıldığında normal isimlendirilmiş bir fonksiyona göre cağrı yapmaya göre
ekstra bir maliyeti var mı ? 
hayır yok.



#include <string>

int main()
{

    std::string s1{"ahmet"};
    std::string s2{"can"};

    auto s3 = s1 + s2;//biz s1 ve s2 yi toplama operatorun operantları yapatık ama derleyici burda bir
                     //fonksiyon cağırdı. 

    if(s1==s2)
    {
        //tutuğu nesnelerin eşitliği karşılaştırılıyor, bunun için de fonksiyon çağrılır.
    }

    //derleyici koda bakarak operatorun operanndı olan sınıf nesnesi ifadesini fonksiyon çağrıısına dönüştürüyor.
    //runtime maliyeti yok.


    return 0;


KURALLAR:


1. global operator function

iki ihtimalden birincisi global functiona yapılan bir çağrıya dönüştürmesi. çağrılan fonksiyona global operator function denir.

2. member operator function

non-static olmak zorunda(sınıfın static üye fonksiyonları operator overloading mekanizmasında kullanılamıyor)

3.olmayan bir operatorun overload edilmesi mümkün değil. operator setinde bulunması lazım
x @ y; //olmayan operator overload edilemez.

4. bu mekanizmanın kullanılması için operantlardan birinin sınıf türünden olması lazım.
!ival
i1 * i2;//derleyici bir fonksiyon çağrısına dönüştüremez

5. bazı operatörler overload edilemiyor.
overload edilebilen operatorler çok fazla, edinemeyenler:

-nokta operatoru 
-sizeof operatoru
:: çözünürlük operatoru
.* operatoru
? : ternary operator
typeide operatoru


* operatoru 
-> ok operatoru
& adres operatoru 
[ ]
()
tür donüştürme operatoru
 overload edilebiilirler.


Sınıfın özel üye fonksiyonu olan atama operatoru
üye operator fonksiyonu olmak zorunda
special member function = 
[ ]

6. Default argument alamazlar
function call() 

7.operatorlerin arity sini değiştiremeyiz

8. Tüm operator fonksiyonları ister üye ister de global olsun isimleri ile cağrılabilir

9. operator öncleliik seviyesi ve operator öncelik yönü değiştirilemez

class Myclass{
    Myclass operator*(Myclass)const;
    Myclass operator+(Myclass)const;
    bool operator<(Myclass)const;

    int main()
    {
    Myclass m1,m2,m3,m4;
    auto f= m1*m2+m3>m4;
//öncleik ne olur ? burada çarpma toplama küçüktür şeklinde öncleikler sıralanır.
//auto f? ((m1*m2)+m3)<m4;
    f = m1.operator*(m2).operator+(m3).operator<(m4);//işi kolaylaştırır.
    
    return 0
    }


};
 


}
*/

