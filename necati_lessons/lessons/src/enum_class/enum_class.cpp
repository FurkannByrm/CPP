#include "enum_class.hpp"


int main()
{
    Status st;

    int status_number = st.ERROR;
    std::cout<<status_number<<std::endl;
    
    //RULES

    enum color{ white, yellow, red };
    
    color mycolor = white;
    int color_number = mycolor;// otomatic type convertion but mot valis in enum class
    // mycolor = 6 is not valid code 

/*2. enum class (Scoped Enumeration) Nedir?

enum class, modern C++'la (C++11) birlikte gelen daha güvenli ve kapsamlı 
(scoped) bir enum türüdür. Temel farkı, ad alanı (scope) oluşturması ve tip güvenliğini artırmasıdır.

Özellikleri:

    Ad Alanı (Namespace) Sağlar:
    Enum değerleri doğrudan kullanılamaz; enum türüyle birlikte belirtilmelidir.
    Tip Güvenliği:
    Farklı enum türlerinin değerleri arasında doğrudan karşılaştırma yapılamaz.
    Varsayılan Tür:
    Değerler, int dışında başka türler de olabilir.*/


    enum class colooor{ white, yellow, red };

    colooor mycloooor = colooor::white;
    //int ival = mycloooor; //otomatic type convertion not valid
    int ival = static_cast<int>(mycloooor);





    return 0;
}