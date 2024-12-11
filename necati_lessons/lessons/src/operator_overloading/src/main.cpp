
#include "mint.hpp"
#include <iostream>




int main(){

Mint m1, m2{20};

 std::cout << m1<< " "<< m2<<"\n";//burada cout nesnesini fonksiyona arguman olark gondermis oluruz
 std::cout<<"iki sayi giriniz : ";
 std::cin>>m1>>m2;
 std::cout<<m1<<" "<<m2<<"\n";

if(m1<m2)
    std::cout<<m1<<" "<<m2;


if(m1==m2)
    std::cout<<m1<<" "<<m2;



std::cout<< m1 << " < "<<m2<<" = "<<(m1<m2)<<"\n";
std::cout<< m1 << " <= "<<m2<<" = "<<(m1<=m2)<<"\n";
std::cout<< m1 << " > "<<m2<<" = "<<(m1>m2)<<"\n";
std::cout<< m1 << " >= "<<m2<<" >= "<<(m1>=m2)<<"\n";
std::cout<< m1 << " == "<<m2<<" == "<<(m1==m2)<<"\n";
std::cout<< m1 << " != "<<m2<<" != "<<(m1!=m2)<<"\n";
    
std::cout<< m1 << " + "<<m2<<" = "<<m1+m2<<"\n";
std::cout<< m1 << " - "<<m2<<" = "<<m1-m2<<"\n";    
    return 0;
}