// string 직접 구현 
// 1. 문자(char)로부터의 문자열 생성, C 문자열(char *)로부터의 생성
// 2. 문자열 길이를 구하는 함수 
// 3. 문자열 뒤에 다른 문자열 붙이기
// 4. 문자열 내에 포함되어 있는 문자열 구하기 
// 5. 문자열이 같은지 비교 
// 6. 문자열 크기 비교 (사전 순)
#include <iostream>
#include <string.h>

class MyString {
    char* string_content; // 문자열 데이터를 가리키는 포인터
    // 객체에 문자열 데이터를 직접 보관하는 것이 아니라 
    // 그 저장된 공간을 가리키는 포인터를 보관하는 이유는, 저장된 공간을 가리키는 방식으로 하면 그 메모리를 해제한 뒤, 다시 할당할 수 있다.
    int string_length; // 문자열 길이 

    public:
    MyString(char c); // 문자 하나로 생성

    MyString(const char* str); // 문자열로부터 생성
    MyString(const MyString& str); // 복사 생성자
    ~MyString();

    int length() const;
    void print() const;
    void println() const;
    
    MyString & assign(const MyString& str);
    MyString & assign(const char * str);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i=0; i != string_length; i++) string_content[i] = str[i];
}
// 복사 생성자
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    for (int i=0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete [] string_content;}

// 문자열 길이 반환
int MyString::length() const { return string_length; }

// 문자열 출력 
void MyString::print() const {
    for (int i=0; i!= string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const{
    for (int i=0; i!= string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > string_length) {
        // 다시 할당해줘야 한다. 
        delete[] string_content;
        string_content = new char[str.string_length];
    }
    for (int i=0; i != str.string_length; i++) { 
    string_content[i] = str.string_content[i];
    }
    return *this;
    }
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > string_length) {
        delete[] string_content;

        string_content = new char[str_length];
    }
    for (int i=0; i!=str_length; i++) {
        string_content[i] = str[i];
    }
   string_length = str_length;
return *this;
}

int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
    return 0;
}
