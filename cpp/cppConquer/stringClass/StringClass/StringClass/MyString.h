#pragma once

class MyString
{
public:
    // 생성자
    MyString(const char c); // 한 글자만 넣었을 때
    MyString(const char* str); // 문자열을 넣었을 때
    MyString(const MyString& str); // 복사생성자
    // 소멸자
    ~MyString();
    // 문자열을 출력해주는 함수(print, println)
    void print();
    void println();
    // 문자열 길이를 리턴하는 함수(length) 
    int length();
    // 문자열 대입 함수(assign)
    void assign(const MyString& str);
    void assign(const char* str);
    // 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수 (capacity)
    void reserve(int n);
    int capacity();
    // 특정 위치의 문자를 리턴하는 함수(at)
    char at(int idx);
    // 특정 위치에 특정 문자열을 삽입하는 함수(insert)
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, char c);
    MyString& insert(int loc, const char* str);
    // 특정 위치의 특정 개수의 문자를 지우는 함수(erase)
    MyString& erase(int loc, int num);
    // 특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;
    // 두 문자열을 사전식 비교하는 함수(compare)
    int compare(const MyString& str) const;

protected:
    char* string_content; // 문자열을 가리키는 포인터
    int string_length;// 문자열 길이
    int memory_capacity;// 문자열에 할당한 메모리 크기 
};