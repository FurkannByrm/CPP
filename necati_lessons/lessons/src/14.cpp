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
*/
#include <cstdlib>
#include <iostream>
#include <memory>
#include <new>

/*
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


*/

/*
class ın member functionları için redecleration söz konusu değildir.
SCOPE LEAKAGE:
bir identifier kullanılan scope alanı dışında da kullannılma ihtimali varsa
bu durum gecerli olur.
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
*/


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

class Point{

    public:
        Point(): ax{0}, ay{0}, az{0}
        {
            std::cout<<"Point ctor this: "<<this<<std::endl;
        }
        Point(int x, int y, int z) : ax{x}, ay{y}, az{z}
        {
            std::cout<<"Point(int x, int y, int z) this: "<<this<<std::endl;
        }
        ~Point()
        {
            std::cout<<"Point destructor : "<<this<<std::endl;
        }
        void print()const
        {
            std::cout<<"["<<ax<<", "<<ay<<", "<<az<<"]"<<std::endl;
        }
        void set(int n, int m, int l)
        {
            ax = n, ay= m, az = l;
        }

    private:

    int ax, ay, az;

};


/*
int main()
{
    //derleyici new operatörü karşılığında ne yapıyor?
    //new operatörü ayrı bir terim operatör new fonksiyonu ayrı bir terim
    //void* operator new(size_t n) malloc c++ cası.
    //aslında burada doğrudan malloc da çağıraılabilirdi ama arka planda bazı işleri yapıyor
    //o yüzden kullanılamıyor. operatör new fonksiyonu yer elde etmeyi başarırsa tıpkı malloc da olduğu gibi
    //elde ettiği bellek blogunun adresini döndirecek. ama operator new başarısız olursa exception handing
    //mekanizması devreye girecek ve operator new fonksiyonu bad alloc class türünden bir exception throw edecek
    //başarısızlık duurumunda artık bu fonksiyon malloc da olduğu gibi başarısızlık durumda yani bellek blogunu elde
    //edememesi durumunda NULL ptr döndürmuyor
    //bu ifade karşılığı derleyicinin şöyle bir kod ürettiğini düşünebiliriz:
   //((operator (new(sizeof(Point))))->Point(12,5,3);
   std::cout<<"main devam ediyor"<<std::endl;
   Point *p = new Point(12,5,23);
   //dinamik ömürlü bir nesneyi new operatçrü ile hayata getirmek arka planda iki ayrı fonksiyon çağırmak demek.
   //biri bu dinamik ömürlü nesnenin yerini ayırmak için çağrılan fpnksiyon, operator new
   //diğeri de ctor cağrılması
   // Point *p = new Point(12,5,23);
   // auto p = new Point(12,5,23);
   // dinamak ömürlü nensnenin hayata gelmesi ve hayatınınn bitmesinden biz sourmluyuz birze garbage collector durumu yok.
   // işi biten nesnenin otomatik olarak o çöpü toplayan,nesne ölümünü sağlayan ayrı bir tred koşmuyor. bunlardan biz sorumluyuz
   // hayata nasıl getirdiysek biz son vereceğiz. java c# a göre farklı

   std::cout<<"p = "<<p<<std::endl;
   p->print();
   std::cout<<"main devam ediyor"<<std::endl;

   //operator delete -> void operator delete(void *vp); //free
   //operator delete ile nasıl bir kod üretir ?
   //delete p yazdığımızda bu adresle destructor cağrılır
   //p->~Point(), sonra operator delete(p); fonksiyonuna bu adresi argüman olarak geçer
   //böylece operatör new in elde ettiği gasp ettşği adres geri verilmiş olur
   //şu ana kadar yazdığımız kodda destructor cağrılmadı. ve new operatörü ile elde edilen
   //bellek alanı geri verilmedi.
   delete p;//bellek alanı geri verildi
   //Program sonlandıktan sonra heap deayrılan o bellek blogu herhangi bir şekilde kullanılabilir

    return 0;
}

programcı operator new i overload ederse, new kendi tarafımızdan yazılırsa ve operator new fonksiyonu kullanılırsa
benim yazdıüım new fonksiyonu çağrılır.
*/

void *operator new(size_t n)
{
    std::cout<<"operator new called n : "<<n<<std::endl;//kendisinin ç.ağrıldığını yazdırdı
    void *vp = std::malloc(n);//mallocon geri dönüşünü bir pointer da tuttu
    if(!vp){ //başarısız olursa exception handing de throw etti
        throw std::bad_alloc{};
    }
    std::cout<<"adress of allocated block : "<<vp<<std::endl; //elde edilen bellek bloğunun adresini yazdırıp geri döndürdü
    return vp;
}

void operator delete(void *vp)//adresi aldı
{
    std::cout<<"operator delete called vp : "<<vp<<std::endl;//çağrıldığını gösterdi
    if(vp){//null değilse clear ladı
        std::free(vp);
    }
}


/*
int main()
{
   std::cout<<"main devam ediyor"<<std::endl;
   Point *p = new Point(12,5,23);
   std::cout<<"p = "<<p<<std::endl;
   p->print();
   std::cout<<"main devam ediyor"<<std::endl;
   delete p;

    return 0;
}
dinamik ömürlü nesnelerle ilgili problemler:

1. eğer nesne delete edilmezse
a) destructor cağrılmaz(resource leak) bu durum kullanılan kaynakların geri verilmesi sorununu doğurur.
b) operator delete fonksiyonu çağrılmaz() 12byte lik bellek blogu geri verilmemiş olur

2. dangling ptr

eğer dinamik ömürlü nesne adresini başka pointerlara kopyalardsanız
Point *p{ new Point{12,5,23} };
Point *p2 = p;

std::cout<<"p= "<<p<<std::endl;
p->print();
delete p;
delete ettikten sonra p ve p2 pointer ın değeri olan adres gecerli değildir
dinamik ömürlü nesnenin ömrü bitmesine rağmenbiz bu nesneyi hala hayattaymıi gibi
kullanırsak dangling ptr kullanmış oluruz.

3.double deletion

ptr i kopyalıyorsunuz ve bunların aynı nesneyi gösteridğini unutup ikisini de
delete etme durumu

Point *p{ new Point{12,5,23} };
Point *p2 = p;

std::cout<<"p= "<<p<<std::endl;
p->print();
delete p;
delete p2; //dangling ptr delete operatorune o adresi verdiğinizde tanımsız davranış.


buraya kadar kurallarımız
dinamik ömürlü nesne kullanırken onları delete etmeyi unutmayacağız,
delete ettiğikten sornra dangling ptr ları kullanmıycaz.
double deletion duruumu yaratmaycağız.

2.NEW OPERATORU(array new)

Birden fazla dinamik dizi oluşturuyor. Belirli bir türden öğelerin oluşturduğu dinamik dizi.

int main ()
{

    int n;
    std::cout<<"kac  nesne ? ";
    std::cin>> n;
    Point *p = new Point[n];
    std::cout<<"main devam ediyor"<<std::endl;
    //bu durumda default ctor kullanılacak ve n tane öğeyi içeren dinamik bir point diizsi oluşturulacak
    //her öğer için ctor cağrılcak. n değeri kadar ctor cağrılacak.
    //Point *p = new Point[n];// burdan elde ettiğim bu dinamik dizinin adresi, bu adresteki nesnelerin hepsine
    //ptr aritmetiği ile erişebilirim.
    //ama yine delete etmem gerekiyor bunların hayatını bitirebilmek için.
    //bu kodda dinamik bir dizi oluşturdu ve dinamik dizinin her bir öğesi iöin ilgili adres this ptr olrark kullanılarak
    //ctor cağrıldı.
    //delete p; endefined behavior olur.
    //yani array new ile hayata getirdiğiniz diziyi array delete ile delete etmemiz gerekiyor:
    delete[]p;
    std::cout<<"main devam ediyor"<<std::endl;

    //bunu coğu zaman kullanmayacağız. hatta array olmayan dinamik nesne oluştumak operatorü new i kullanmayacağız.
    //NEDEN?
    //bu operatorleri kullanıp doğrudan raw ptr, naked ptr lara bağlamak yerine. kendisi bir sınıf türünden nesne olan
    //ama ptr interface ine benzer interface sahip, smart ptr diye isimlendirilen sınıflar türünden nesnelerle tipik olrak dinamik
   //ömürlü nesnelerin hayatını devam ettireceğiz.
   //Bu amaçla kullanılan standart kütüphanenin iki tane önemli sınıfı var.
   // std::unique_ptr
   // std::shared_ptr
   //operator new in smart pointer ile bir alakası yok
   //smart ptr sadece dinamik ömürlü nesnesin hayatını kontrol etmek için.
   // örneğin std::unique_ptr kullanılma nedeni
   //std::unique_ptr nesnesşnin destructor u cağrıldığında std::unique_ptr nin destructor dinamik ömürlü nesneyi delete ediyor.
   //yani biz fiilen dinamik ömürlü nesneyi delete etmek yerine, o nesneyi bir smart pointer nesnesine bağlıyoruz, ve smart
   //pointer nesnesinin ömrü bittiğinde dinamik ömürlü nesne de delete ediliyor.
    }
*/

/*
//smart pointer sınıfların başlık fosyası <memory>:



*/
int main(){
//Point *p = new Point(1,4,7);
//böyle yapmak yerine p gibi pointer olarak kullanılacak ama pointer değil
//bir sınıf türünden nesne pointer interface e sahip bir smart pointer oluşturalım
//std::unique_ptr<Point>p(new Point(1,4,7));
//std::cout<<"main devam ediyor"<<std::endl;
//burada p nesnesinin hayatı bitti, fakat p nin destructoru öyle şekilde yazılmış ki
//p nin destructor ı ctor ile edindiği dinamik ömürlü nesnesnin hayatını bitirdi.
//örneğin kod bu haliyle şu çıktıyı verdi :
//operator new called n : 12
//adress of allocated block : 0x63de17d986c0
//Point(int x, int y, int z) this: 0x63de17d986c0
//main devam ediyor
//Point destructor : 0x63de17d986c0
//operator delete called vp : 0x63de17d986c0

//if statement ile kullanılırsa if blogu dısında p local nesnesinin
//hayatı scope alanı dışına çıkıldığında biter bu sebeple smart pointer kullanımı:
std::cout<<"main başladı"<<std::endl;
if(1)
{
    std::unique_ptr<Point>p(new Point(1,4,7));
    //main devam ediyor yazısı cıkmadıan point sınıfının destructorı oluştururlur

}
    std::cout<<"main devam ediyor"<<std::endl;


}
//çıktı:
/*
main başladı
operator new called n : 12
adress of allocated block : 0x59a7337e46c0
Point(int x, int y, int z) this: 0x59a7337e46c0
Point destructor : 0x59a7337e46c0
operator delete called vp : 0x59a7337e46c0
main devam ediyor

Biz ileride smart ptr nesneleri ile dinamik ömürlü nesneleri kontrol etmek istiyoruz.
modern c++ ın en önemli öğeleri

Bir sınıfın destructor ı fiilen çağrıldığı çok az özel durum var.

C de adres tutuan sadece pointer var
C++ de hem pointer var hem de baika adres tutuan kendisi poşiter olmamasına rağmen
pointer gibi davranan bir durum var;
p->print();
p->set(4,4,4);
p pointer olamamsına rağmen pointer interface ine sahip sınıflar var. gerçekte pointer olmayan bu
sınıflar c++ standart lib inde bir hayli fazla.
fakat bu sınıflar bir kısmı: [uniq_ptr ve shared_ptr] özel bir amacla kullanılıyorlar.
hangi özel amaçla kulllanılıyor?
dinamik ömürlü nesnelerin hayatlarını kontrol etmek için, onlara smart ptr deniliyor.
pointer arayüzüne sahip yani nesnelerin ptr gibi kullanılacak bazı standart sınıflar var.
ama bunların hepsine smart ptr denöiyor. burada kastedilen dinamik ömürlü nesnelerin hayatını kontrol ediyor
smartlıgı da kendi hayatı bitince kontrol ettiği dinanmik ömürlü nesnenin hayatını bitirebiliyor. bu garbage
collecetor sistemi değil ama kodlamayı çok daha güvenli hale getiriyor.
mesela burada gerçek pointer kullanmıi olsaydık
p->print();
p->set(4,4,4);
bunu delete etmek zorunda kalacaktık double deletion problemi olacaktı vs vs
unique_ptr kullanarak daha güvenli hale getiririz. maliyeti de 0 dır.

unique_ptr ve shared_ptr arasındaki fark :
unique_ptr exculusive ownership denilen stratejiyi implemente ediyor. exculusive ownership şu demek; bir nesnenin 1 tane sahibi var
sahibinin hayatı bittiğinde o nesnenin o kaynağın da hayatı bitiyor.
 std::unique_ptr<Point>p(new Point(1,4,7));
 mesela burada dinamik ömürlü bir nesne bir kaynak var onu unique_ptr nesnesine bağladım, emin olduğum şey ne zaman p nin hayatı
 bitecek, p nin hayatı bittiğinde dinamik ömürlü nesnenin de hayatı bitecek. yani artık dinamik ömmürlü nesnenin hayatını neye endeklsedim
 burada p değişkenine.
 peki bunu bir başka nesneye kopyalarsam ? işte unique_ptr sınıfının en önemli özelliği de kopyalamaya kapatılmış olmasıdır.
böylece aynı nesneyi birden fazla ptr nin göstermesi, aynı dinamik ömürlü nesneye birden fazla ptr ile erişme olanağı kalmıyor.
bunu sağlayan unique_ptr sınıfını kopyalamaya karşı kapatılmış bir sınıf olmasıdır. bu ne demek ? copy ctor ve copy assigment ı delete edilmiştir.
delete edilmemiş olsaydı
auto p1 = p; syntax hatası olmazdı. delete edilmiş bir fonksiyona çağrı yapıldığının hatasını alırız.
fakat unique_ptr sınıfı taşımaya açık. move ctor ve move assigment ı vardır. peki bu unique_ptr nesnesini başka bir unique_ptr nesnesine
taşıdığımızda ne oluyor ?

biri mülkiyeti bırakıyor.

std::unique_ptr<Point>p(new Point(1,4,7));
auto p1 = move(p); //sağ taraf değeri haline getirdik, böylece artık p nin kaynağını p1 aldı.

1 Ornek
 bir sınıf olsun, bu sınıfınveri elemanlarında biri kopyalamaya karşı kapatılmış olsun.
 buna en iyi örnek unique_ptr.

class Myclass{

    public:

    Myclass() = default;
    std::unique_ptr<std::string> uptr;
    //norömalde bu sınıfın copy ctor unu compiler yazacaktı.
    //ruele of zero kullansak ne olurdu?
    //move only bir sınıf türünden bir member ı varsa bir sınıfın, bu durumda programcı rule of zero yaparsa ne olur?
    //bu sınıfın copy ctorunu derleyici yazacak, copy assigment ını derleyici yazacak. derleyicinişn yazdığı copy ctor
    //copy assigment veya özel fonksiyon eğer bir sentax hatası oluşturursa(gecersiz bir kod yazma durumuna düşerse syntax hatası vermek yerine)
    //derleyici onları delete ediyordu. istisnası delete edilecek işlemler move işlevleri ise bunlar hiç bildirilmemiş kabul edilir.
    //derleyiciin yazdığı copy ctor öğeleri birbirine kopyalıyordu. ama unique_ptr kopyalayahn kurucu işlevi delete edilmiş olduğu için oluşan
    //sentax haatası ile myclass class ı da copy ctor u delete edilecek.
    //compiler move memberlar ı yazıyordu, her bir öğeyi diğer bir öğe ile taşıyan kruucu işlevi çalıştırıyodu,taşıyan operator fonksiyonunu
    //kullanrakn yazıyordu. Derleyicinin oluşturduğüu move ctor da ve derleyicinin oluşturduğu move assigment da hiç bir problem yok. otomatik
    //olrak benim sınıfım non copyable but movable.

};

int main(){

    Myclass m1, m2;
    Myclass m3 = m2; //syntax hatası işaretledi, copy ctor delete edilmiş.
                    //ama move memberları delete ederse bunlar hiç bildirilmemiş kabul edilir

    Myclass m3 = std::move(m2);//syntax hatası yok cunku derleyici move member ı yazdı cunku derleyicinin yazdığı move aslında hayata gelen nesnenin
    //uptr ogesine diğer nesnenin yani m2 nesnesini uptr sine taşıyor
    //aynı şey atama için degecerli
    m1 = m2; //syntax hatası çunkü bu delete edilmiş bir fonksiyon
    m1 = std::move(m2)// taşıma semantiği devreye girecek.
    //rule of zero zaten beim istediğim bir şey sınıf aboyle bir veri elemanı koyuyorsak:
    std::unique_ptr<std::string> uptr;
    //bu zaten tipik olarak kopyalanmasını değil taşınmasını istiyorum demektir.
    //taşınmasını istiyorum anlamına gelecek, taşınması için derleyiciin oluşturduğu taşıyan operator fonksiyonu, ve taşıyan kurucu işlev
    //move ctor ve move assigment bunu yapacak.
    //eğer boyle bir fonksiyon varsa myclass sınıfı copy e kapalı ve taşımaya acıksa bu fonksiyonu cağırmanın tek yolu bu fonksiyona 
    //sağ taraf değeri gecmek.

    //kopyalamaya karşı kapatılmış
    void func(std::unique_ptr<Point> x);

    int main(){
     //bu fonksiyonun parametre deüişkenin unique_ptr türünden(kopyalamayb karşı kapalı, taşımaya acık)
     //o zaman bu fonksiyonu neyle cağırırız. unique_ptr sınıf turunden bir r value expression ile cağırırız

     std::unique_ptr<Point> uptr{ new Point{1,2,4}};
     func(uptr); //eğer bu fonksiyonu ile cağırısanız bu kopyalama olduğu için syntax hatası olur
     func(std::move(uptr));// bir syntax hatası olmaz cunkü r value göndermiş oluruz.
     yada void func(std::unique_ptr<Point>& x);
     yapip referans parametresin l value gecevcegiz
     func(uptr); legal olur bu sayede
     Açıklama:

    Lvalue Referans Geçişi:
        func(std::unique_ptr<Point>& x) bir unique_ptr'yi referans yoluyla alır.
        Bu nedenle, fonksiyonun içinde unique_ptr üzerinde herhangi bir işlem yapabilirsiniz (örneğin, işaret edilen nesneyi değiştirmek).

    Sahiplik Transferi Olmaz:
        uptr hala nesnenin sahibidir. func sadece bu unique_ptr'ye bir referans üzerinden erişir ve üzerinde işlem yapabilir.
        Sahiplik transferi olmadığı için uptr geçerliliğini korur.

    Bellek Yönetimi:
        uptr hala aynı kaynağı işaret eder ve fonksiyondan sonra kaynağı yönetmeye devam eder.

Önemli Noktalar:

    func(std::unique_ptr<Point>& x) kullanımı, unique_ptr'nin yönetim modeliyle çelişmez. Çünkü kaynak transferi yerine, sadece referans yoluyla geçiş yapılır.
    Bu yaklaşım, bir unique_ptr'yi taşımak istemediğiniz ama üzerinde işlem yapmak istediğiniz durumlar için uygundur.


    }


}

otomatik ve dinamik ömürlü nesnelere smart pointer lar bağlanır ve bunlar tanımlı scope alanı dışına cıktıklarında
ömürleri bitmiş olur.
fakat otomatik ve dinamik ömürlü nesnelerin kullanım alanları birbirlerinden farklı. yukarıda örneklerde otomatik
ömürlü nesnelerle de yapılabilirdi.


*/
