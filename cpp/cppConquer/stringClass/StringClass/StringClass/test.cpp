#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;


int main() 
{
    MyString str1("abcdef");
    MyString str2("abcde");

    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
    return 0;
}
