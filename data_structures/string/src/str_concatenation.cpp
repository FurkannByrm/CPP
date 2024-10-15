#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <string>

//1. using std::string::append()
//2. using + operator
//3. using strcat() [Use this method when concatenating C-style strings (character arrays). Also suitable for legacy code that may run in C compilers.]
int main()
{
    //1. method
std::string str1 = "hello ";
std::string str2 = "world";
str1.append(str2);
std::cout<<str1<<std::endl;

    //2. method
std::string str3 = "merhaba ";
std::string str4 = "dunya";

str3 = str3 + str4;
std::cout<<str3<<std::endl;

    //3. method

char str5[] = "hello ";
char str6[] = "world";
std::strcat(str5, str6);
std::cout<<str5<<std::endl;

    //4. method
std::string str7("hiii ");
std::string str8("guyss");


    return 0;
}
