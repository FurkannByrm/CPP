/* 
Operator Overloading (Operator Yüklemesi) Notları

Operator overloading (operatör yüklemesi), bir sınıf nesnesini bir operatörün operandı haline getirdiğimizde, derleyicinin bunu bir fonksiyon çağrısına dönüştürmesini sağlar. Bu mekanizma, belirli operatörleri özel olarak tanımlamamıza olanak tanır.
Temel Prensipler

    Global Operator Fonksiyonları
    Operatörün global bir fonksiyon olarak tanımlanmasıdır.
    Örneğin:

bool operator==(const MyClass& lhs, const MyClass& rhs);

Üye Operator Fonksiyonları
Sınıfın içinde tanımlanır ve non-static olmak zorundadır.
Örneğin:

class MyClass {
    bool operator==(const MyClass& other) const;
};

Olmayan Operatörler Yüklenemez
Yalnızca dilde mevcut olan operatörler yüklenebilir. Örneğin, @ gibi bir operatör yüklenemez.

Operandlardan Biri Sınıf Türünden Olmalı
En az bir operand sınıf türünden olmalıdır.

    MyClass m1, m2;
    auto result = m1 + m2; // Geçerli
    int a = 5, b = 6;
    auto sum = a + b; // Operatör yüklemesi gerektirmez

    Yüklenemeyen Operatörler
    Aşağıdaki operatörler yüklenemez:
        ., .*, ::, sizeof, ? :, typeid

    Default Argument Kullanılamaz
    Operatör fonksiyonları varsayılan argümanlar alamaz.

    Operatör Arity’si Değiştirilemez
        Unary operatörler, bir parametre alır (global) veya parametre almaz (üye).
        Binary operatörler, iki parametre alır (global) veya bir parametre alır (üye).

Operatörlerin Tanımlanması
Unary Operatörler

    Global Fonksiyon: 1 parametre alır.
    Üye Fonksiyon: Parametre almaz.

class MyClass {
public:
    bool operator!() const; // Üye fonksiyon
};

bool operator!(const MyClass& obj); // Global fonksiyon

Binary Operatörler

    Global Fonksiyon: 2 parametre alır.
    Üye Fonksiyon: 1 parametre alır (sol operand *this olur).

class MyClass {
public:
    MyClass operator+(const MyClass& other) const;
};

bool operator<(const MyClass& lhs, const MyClass& rhs); // Global

Operatör Önceliği ve Yönü

Operatör yüklemesi, operatör önceliğini veya yönünü değiştirmez. Öncelikler dilde tanımlı olan kurallara göre çalışır.

MyClass m1, m2, m3, m4;
auto result = m1 * m2 + m3 < m4; // Öncelik: *, +, <

Referans ve Kopyalama Seçimi

    Operatör fonksiyonlarının dönüş türleri, maliyeti ve kullanım amacına göre belirlenir.

    MyClass operator+(const MyClass&, const MyClass&); // Verimli ve güvenli
    MyClass& operator+=(MyClass&, const MyClass&);     // `*this` değiştiği için referans döner

Akış Operatörleri (<< ve >>)

Akış operatörleri genellikle global olarak tanımlanır.

std::ostream& operator<<(std::ostream& os, const MyClass& obj);
std::istream& operator>>(std::istream& is, MyClass& obj);


 Referans Dönüş Türleri ve Performans

    L-Value ve R-Value:
    Operatör fonksiyonlarının dönüş türü, sınıfın kullanımı ve performans ihtiyaçlarına göre belirlenir.
        Değişiklik yapmayacak fonksiyonlar const olarak tanımlanır.
        Büyük nesnelerin kopyalanmasından kaçınmak için referanslar kullanılabilir.


Referans Dönüş Türleri ve Performans: L-Value, R-Value, ve PR-Value Kavramları

C++'da referans dönüş türleri (reference return types), performans açısından oldukça önemlidir. 
Bu kavramı anlamak için önce temel C++ değer kategorilerini ele alalım:
Değer Kategorileri: L-Value, R-Value, ve PR-Value

    L-Value (Locator Value):
        Bir nesnenin bellekteki bir konumunu temsil eder.
        Sağ tarafta da kullanılabilir (int x = y;).
        Özellik: Adres alınabilir (&x geçerlidir).
        Örnek:

    int x = 5;
    int &ref = x; // L-Value Referansı

R-Value (Right-Value):

    Geçici (temporary) değerleri ifade eder. Bellekte kalıcı bir konuma sahip değildir.
    Özellik: Adresi alınamaz.
    Örnek:

        int x = 10 + 20; // 30 bir R-Value'dir.

    PR-Value (Pure R-Value):
        Temel R-Value türü. Sabitler veya geçici nesneler.
        PR-Value'lar daha çok bir hesaplama sonucu oluşan geçici değerlerdir.

L-Value ve R-Value Referansları:

    L-Value Referansları (T&):
        Kalıcı nesneleri referans eder.
        Kullanım: Değer üzerinde değişiklik yapmak için.

    int a = 10;
    int &ref = a; // L-Value referansı
    ref = 20;     // a şimdi 20 oldu.

R-Value Referansları (T&&):

    Geçici nesneleri referans eder.
    Kullanım: Move semantiği (taşıma işlemleri) için.

        int &&rref = 10; // R-Value referansı

Neden Referans Dönüş Türleri Kullanılır?

    Verimlilik:
    Büyük nesneler kopyalanmak yerine referansla döndürülerek performans artırılır.

std::vector<int>& getVector(); // Büyük bir nesne kopyalanmaz, referans döner.

Zincirleme Operatörler:
Referans dönüşü, işlemlerin zincirlenmesini sağlar:

    class MyClass {
    public:
        MyClass& operator+=(const MyClass &rhs) {
            // İşlem burada yapılır.
            return *this; // Referans döner.
        }
    };
    MyClass a, b;
    a += b += b; // Zincirleme kullanım.

R-Value Referansları ve Move Semantiği:

    Move Semantiği (Taşıma İşlemi):
    Büyük nesneleri kopyalamak yerine, sahipliği taşır. Bu işlem, özellikle geçici nesnelerde etkilidir.

    class MyClass {
    private:
        int *data;
    public:
        MyClass(MyClass &&other) { // Move Constructor
            data = other.data;
            other.data = nullptr; // Kaynak serbest bırakılır.
        }
    };

Özet:

    L-Value Referansı: Kalıcı nesneleri temsil eder. Operatör fonksiyonlarının dönüş türü olarak kullanılırsa nesne üzerinde değişiklik yapılabilir.
    R-Value Referansı: Geçici nesnelerle çalışmak için kullanılır ve move semantiği sağlar.
    PR-Value: Saf geçici değerlerdir. Bellekte kalıcı bir yeri yoktur, genellikle geçici hesaplama sonuçlarıdır.

Performans açısından, büyük nesnelerin gereksiz kopyalanmasını önlemek için referans dönüş türleri tercih edilmelidir. 
Bu, özellikle operator overloading ve büyük sınıf nesneleri için kritik bir optimizasyon yöntemidir.

*/

#include <iostream>

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}

    MyClass& operator+=(const MyClass &rhs) {
        value += rhs.value;
        return *this;  // L-Value döndürüyoruz
    }

    friend std::ostream& operator<<(std::ostream &out, const MyClass &obj) {
        out << obj.value;
        return out;
    }
};

// sinifa operator fonksiyonu koup koymamakta client code daki intuitive sezgisel bir mekanma olmasi lazim

int main() {
    MyClass a(10), b(20);
    a += b; // operator+= çağrısı
    std::cout << a << std::endl; // operator<< çağrısı
}

/* 
Sonuç

Operator overloading, C++’da güçlü ve esnek bir özelliktir. 
Mantığını anlamak, kodun daha sezgisel ve temiz olmasını sağlar. 
Ancak, iyi tasarlanmış bir API ve sınıf yapısı oluşturmak için dikkatli kullanılmalıdır.

kullananin kafasini karistiracak operator overloading den uzak durmaliyiz
sinif nesnesini degistirmeyecek uye fonksiyonlarin const olmasi lazim

binary bir operatorun operantlarini degistirmemsi soz konusuysa global operator fonksiyonlari bunlari ref semantigi ile geciyorsaniz
const ref olacak

fonksiyon geri donus degeri turu operatorle olusturulan ifadenin value category sine uygun olusturulacak
l value expression olusturan operator ifadelerine karsilik gelen fonskiton cagrilarina referans donsurecek
pr value da ifadelere karsilik gelen fonsksiyon cagri ifadesinin l value expression olmasi icin geri donus degerleri referans olacak


Simetrik Operatorler

a op b 
b op a anlamli ve ayni isi takip ediyor.


s1< s2 ne anlama geliyorsa
s2 < s1 de ayni anlama geliyor

date - n tarihten tamsayi cikarilmasi
n - date simetrik olmaz
sinif nesnesini degistirmeyecek simetrik binary operatorler global operator olarak yazilmali
 
//FRIEND DECLERATION

//sinifa ait olmayan bir kod sinifin bir fonksiyonu olmayan bir fonksiyon sizin sinifinizin private bolumunuze eriusmesi durumunda syntax
// hatassi olmasin istiyorsunuz. bu bildirime friend bildirimi deriz
// eger uygun dogru syntax da bildirim yapilirsa syntax hatasi olarak degerlendirilmez
//special member fubction kategorisinde de olabilir
//friend lik verilen class kendi private memberlarina erisim vermis olmaz.    
// 3 ayri kategoride kullanilir ve ayni aronda kullanilmaz

// 1.kategori = global bir fonksiyona arkadaslik vermek
// derleyiciye bu global fonksiyon benim frien im buna erisim verdigimdesyntax hatasi olarak gorme.

// 2.kategori= bir sinifin uye fonksiyonuna arkadaslik vermek

// 3.kategori = bir sinifa arkadaslik vermek.

// bir sinif kendi fonksiyonuna friend veremez cumku zaten erisim soz konusudur.


//kategori 2: bir sinifin uye fonksiyonunu friend etmek

class Fruko{ //class Fruko; ile incoplete decleration da mumkun degildir

    public:

    void foo();// fruko sinifin public bolumune erismesini istiyoruz 

    private:

};

//friend konusu icin ornek yapalim;
// kategori 1: global fonksiyonu frien etmek

class Myclass{
    private:
    int mx;
    void pfunc();
    friend void gfoo(int);
    //fonksiyonun bildirimini derleyici aramiyor.
    // bu nedenle bu zamana kadar gfoo() hic yazilmamis 
    // bile olsa namelook up la aranmadigini bilmeliyiz. 
    // yani bu ayni zamnada global bir fonksiyonun da bildirimi. 
    //compiler bunun global fonksiyon oldugunu nerden biliyor cunku memeber functionu na 
    //friend lik veremeyiz
    //global fonksiyonu class definition icinde tanimlayamaz ama istisnasi friend fonksiyonlardir

    public:
    
    friend bool operator<(Myclass m1, Myclass m2){ // kucuktur operatoru binary bi operator
    //sinifin uye fonksiyonu olarak tanimlanacaksa 1 parametre almasi lazimdi
    //ama biz cok parametre girerek global tanimlama yaptik.
    // friend vermezsek define edemeyiz cunku class scope da global fonksiyonlar define edilmezler
    return m1.mx < m2.mx;
    //inline fonksiyon olmus oldu.
    }
    int getx()const{
        return mx;
    }
    friend void Fruko::foo();
    friend class Fruko;//bir sinifa komple friend de verilebilir.(forward decleration)
    //artik fruko sinifinin butun member functionlari Myclass private bolumune erisebilir
    //bu durumda compiler in class Fruko nun bildirimine veya tanimina ihtiyaci yok
    //yani Class fruko silinse dahi error olusmaz

};

void gfoo(int x)// ayni sekilde parametesi de Myclass sinifi turunden olabilr
{
    ++x;
    ///
    Myclass m; 
    m.pfunc();// access bu sekilde mumkun oldu
}
// friend bildiriminin sinifin public bolumuyle private bolumuarasinda yapilmasinin ne farki var ?
//sorun cevabi hicbir fark yok. yegane farksiz bir durum cok sukur

void Fruko::foo(){//compiler friend verdigi uye fonksiyonun sinifini gormesi lazim.

    Myclass m;
    m.pfunc();
}

int main(){

}


*/