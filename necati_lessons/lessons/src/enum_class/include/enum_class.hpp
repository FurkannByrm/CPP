#include <iostream>


class Status
{
    public:

    enum state{ OK, ERROR, WARNING };// public access
    

    private:



};

    
/*

enum vs. enum class: Temel Farklar

Özellik	            enum	                                enum class
Ad Alanı (Scope)	Değerler global ad alanında bulunur.	Değerler yalnızca enum tür adıyla erişilir.
Tip Güvenliği	    Zayıf (int türüne otomatik dönüşüm).	Güçlü (otomatik dönüşüm yoktur).
Varsayılan Tür	    int	                                    Belirtilen tür kullanılabilir (uint8_t).
Karşılaştırmalar	Farklı enum'lar arasında karşılaştırma  Farklı enum class türleri karşılaştırılamaz. 
                    mümkün.	


Verimlilik ve En İyi Pratikler:

    Küçük Türler Kullanın:
    Özellikle gömülü sistemlerde veya büyük veri kümelerinde, uint8_t gibi küçük türler performans açısından daha iyidir:

enum class ErrorCode : uint8_t { None, Minor, Major };

constexpr ile Birleştirme:
Derleme zamanı sabitleriyle çalışırken enum class ve constexpr kombinasyonu kullanılır:

constexpr ErrorCode e = ErrorCode::None;

Kullanımda default Case Ekleyin:
Tüm enum değerlerini ele almazsanız, default durumu eklemek iyi bir pratiktir:

switch (e) {
    case ErrorCode::None: break;
    default: std::cout << "Unhandled error";
}




1.numaralandırma sabitlerinin bilinirlik alanları


Düz numaralandırma türlerinde, tanıtılan numaralandırma sabitlerinin kapsamı (scope) numaralandırma türünün kapsamıdır. 
Bu durum numaralandırma sabitleri olan isimlerin aynı kapsamda bulunan diğer isimlerle çakışma riskini arttırır. 
Çok sayıda kütüphanenin bir arada kullanıldığı projelerde numaralandırma sabitleri olarak kullanılan isimlerin çakışması ç
ok sık karşılaşılan bir durumdur:

//traffic.h
enum TrafficLight {Yellow, Green, Red};//screen.h
enum ScreenColor {White, Gray, Green, Red, Magenta, Brown, Black};//simulation.cpp
//#include "traffic.h"
//#include "screen.h"

Yukarıdaki kodda traffic.h başlık dosyasında tanıtılan enum TrafficLight isimli bir tür var. Bu başlık dosyası ile doğrudan 
bir ilişkisi olmayan screen.h isimli başlık dosyası ise enum ScreenColor isimli bir türü tanıtmış. simulation.cpp isimli kod 
dosyası her iki modülün sağladığı hizmetlerden faydalanabilmek için iki başlık dosyasını da #include önişlemci komutlarıyla 
kendi kaynak dosyasına eklemiş. Bu durumu derleyici bir sentaks hatası olarak işaretleyecek. Green ve Red isimleri çakışıyor. 
Aynı kapsamda birden fazla farklı varlık aynı ismi taşıyamaz, değil mi? Kapsamlandırılmış numaralandırma türlerinin sağladığı 
faydalardan birincisi bu. Bu türlerin kendi kapsamları var ve tanıtılan numaralandırma sabitleri, numaralandırma sınıfının kendi 
kapsamında yer alıyor. Yukarıdaki kodda şimdi kapsamlandırılmış numaralandırma türlerini kullanıyoruz:

//traffic.h
enum class TrafficLight {Yellow, Green, Red};//screen.h
enum class ScreenColor {White, Gray, Green, Red, Magenta, Brown, Black};//simulation.h
//#include "traffic.h"
//#include "screen.h"void func()
{
    auto traffic_light = TrafficLight::Green;
    auto screen_color = ScreenColor::Green;
    //....
}
Kapsamlandırılmış numaralandırma türlerine ilişkin sabit isimleri numaralandırma tür ismiyle nitelenmek zorunda. Aşağıdaki gibi 
bir kullanım geçerli değil:

ScreenColor scr_color = Magenta; //geçersiz

Düz numaralandırma türleri ile tanıtılan numaralandırma sabitlerinin ayrı bir kapsamı olmamasına karşın C++11 artık onları da 
numaralandırma tür ismiyle niteleyerek kullanabiliyoruz:

enum Suit {Club, Diamond, Heart, Spade};Suit s = Suit::Diamond;

C++11 öncesi numaralandırma sabitlerinin isim çakışmalarından korunması için bir yapı ile sarmalanması sık başvurulan bir yoldu:

struct SuitWrapper {
    enum Suit { Club, Diamond, Heart, Spade };
};SuitWrapper::Suit s = SuitWrapper::Diamond;

Böyle bir sarmalamanın görece bir avantajı, sarmalayan sınıftan türetme yapılabilmesi. Ancak kapsamlandırılmış numaralandırma 
türlerinden türetme yapılması olanağı yok. İsim çakışmasından korunmak için kullanılan bir başka yöntem de numaralandırma türünün 
tanımını bir isim alanı içine almaktı:

namespace Neco {
    enum Suit {Club, Diamond, Heart, Spade};
}Neco::Suit s = Neco::Diamond;

2.düz numaralandırma türlerine ilişkin sorunlu tür dönüşümleri
Düz numaralandırma türlerine yalnızca aynı türden değerler atanabilir, yani diğer türlerden düz numaralandırma türlerine örtülü 
(implicit) tür dönüşümü yoktur:

enum Color { White, Yellow, Gray, Green, Brown, Black };
enum Font { Arial, Verdana, TimesNewRoman, Courier, Helvetica };int main()
{
    Color c1 = Yellow; //geçerli
    Color c2 = 3; //geçersiz
    Font f1 = Verdana; //geçerli
    Font f2 = Black; //geçersiz
    c1 = f1; //geçersiz
}

Yukarıdaki kodda geçersiz atamaları görüyorsunuz. Numaralandırma türlerine diğer türlerden örtülü tür dönüşümü olmaması yanlış 
yazımlara karşı önemli bir koruma sağlar. Geçersiz olan ilk değer verme ya da atama işlemleri istenerek yapılıyorsa static_cast tür 
dönüştürme işleci kullanılabilir:

Ancak düz numaralandırma türlerinden tamsayı ve gerçek sayı türlerine örtülü (implicit) tür dönüşümü var. Aşağıdaki koda bakalım:

enum Color { White, Yellow, Gray, Green, Brown, Black };int main()
{
    Color c = Green;
    int cnt = 0;
    //...
    int ival = c;
    //...
}
Yukarıdaki kodda int türden ival değişkenine Color türünden c değişkeninin değeriyle ilk değer verilmiş. Dilin kurallarına göre 
kod geçerli. Color türünden c derleyici tarafından int türden 3 değerine dönüştürülecek. Belki de kodlayıcımız ilk değer verme 
işleminde cnt ismini kullanmak yerine yanlışlıkla c ismini yazmıştı. Kapsamlandırılmış numaralandırma türlerinden artık diğer 
türlere örtülü (implicit) dönüşümü geçerli değil:

enum class Color { White, Yellow, Gray, Green, Brown, Black };int main()
{
    Color c = Color::Green;
    int cnt = 0;
    //int i = c; //geçersiz
    int j = static_cast<int>(c); //geçerli
    //...
}

Yukarıdaki kodda i değişkenine verilen ilk değer geçerli değil. Çünkü Color türünden int türüne örtülü (implicit) tür dönüşümü 
yok. Ancak j değişkenine ilk değer verilirken Color türünden değer static_cast işleciyle int türüne dönüştürülüyor. Kod geçerli.

*/