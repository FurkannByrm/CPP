/*
STATIC DATA MEMBERS & FUNCTIONS

1.STATIC DATA MEMBERS
-class ın static member elemanları sınıf nesnesi
size of değerini artırmıyor.
-Class ın static data memberler ı class içinde decleration
yapılır define edilmez.
-static data memberlar ı hpp file da tanımlanırsa one definition
rule ihlal edilmiş olur. .cpp dile da define edilir.
-C++ da bir class ın kendi türünde static data member ı olabilir.
-public veya private olabilirler genellikle const olmayan static
-data memberları private decleration olurlar.
-define "static" keyword kullanılmaz.
-static data member larda ilk değer veren ifadelerde gecen isimler
önce class scope da aranır.
-resolution operatörü ile çağrıldıklarından, static data member
vurgusu yapılmış olur.
-inline function lar gpp de one definidtion rule u ihlal etmezdi
inlibe variabiller c++17 de static inline değişkenler de geldi.
inlline keyword u ile artık hpp de define edilebilirler ve 1 linker
oluşturduğu için odr u ihlal etmez.

2.STATIC MEMBER FUNCTIONS

-Class scope da static member function bir nesne için çağrılmaz.
-hpp file da define edilebilirler.
-cpp de define edilirken static keyword u kullanılmaz.
-this pointer ı olmadığı için class object si gizlice
alınmadığı için class ın non static data member larının isimlerini
doğrudan kullanamazsınız.
-ama static member functionlar static data member ları kullanır.


Static member function ların sınıfın non-static member functionları çağırması:
normalde name look-up da this pointerı non static functionşarın çağrılarında
compiler bunu görür ve çağırır.
Static member functionların gizli parametre değişkeni yoktur.
Ama baika bir static funtionu (member) çağırabilir.


Özetle:

-Class ın member functionlarını ismiyle classın static data memberlarını ve
function larını çağırabilir.

-Class ın static member functionları ismiyle class ın non static data member
larını yada non-static member functionlarını çağıramaz. Parametre class type
ise o gelen parametre ile class member lara erişim mümkündür.

-Static member functionları const olamaz.

void func()const = void func(const Myclass* const this)
doğrudan çağrı yapamaz this parametresi olmadıüı için. ama tanımlı hale getirilebilir.


*/
#define STATIC
#include "static.hpp"

//STATIC void Static::fun(){}
int Static::x = 9; // static member data definition

int main()
{



return 0;
}
