#include <iostream>
#include <string.h>


class MyString{
    char* string_content; // 문자열을 가리키는 포인터
    int string_length;// 문자열 길이
    int memory_capacity;// 문자열에 할당한 메모리 크기 

    public:
    // 생성자
    MyString(const char c); // 한 글자만 넣었을 때
    MyString(const char *str); // 문자열을 넣었을 때
    MyString(const MyString &str); // 복사생성자
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
};

// 생성자
// 한 글자만 넣었을 때
MyString::MyString(const char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
// 문자열이 들어왔을 때
MyString::MyString(const char *str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i=0; i !=string_length; i++) string_content[i] = str[i];
}
// 복사 생성자
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.memory_capacity;
    string_content = new char[string_length];
    for (int i=0; i!=string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
// 소멸자
MyString::~MyString() { delete[] string_content;}

// 문자열 출력
void MyString::print() {
    for (int i=0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() {
    for (int i=0; i!= string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
// 문자열 길이 반환
int MyString::length() {
    return string_length; 
}
// 특정 위치의 문자를 리턴
char MyString::at(int idx) {
    // idx가 out of range라면 NULL 반환, C 스타일의 배열에 담긴 string이었다면 쓰레 값을 반환했을 것
    if (idx >= string_length || idx < 0) 
        return 0; // char이 아닌 NULL을 반환하면 반환값이 non_pointer type이기 떄문에 컴파일 경고가 뜨지만 컴파일은 그대로 진행된다. 자동으로 return 값에 대한 형변환이 이루어진다. 여기서는 그냥 0을 반환한다. 
    return string_content[idx];
}
// 현재 할당된 메모리 크기 확인
int MyString::capacity() {return memory_capacity;}
// 메모리 할당하기
// //현재 메모리 용량이 할당하고자 하는 메모리 용량보다 작을 경우 기존 것을 해제하고 다시 할당
// // 할당하고자 하는 용량이 현재보다 작을 경우에는 에러 반환
void MyString::reserve(int n) {
    if (memory_capacity < n) {
        char *prev_content = string_content;
        memory_capacity = n;
        string_content = new char[memory_capacity];

        for (int i=0; i != string_length; i++) {
            string_content[i] = prev_content[i];
        }
        delete[] prev_content;
    } else {
        std::cout << "memory size is smaller than present size" << std::endl;}

}

// 문자열을 새로 대입
// str의 문자열 길이가 기존보다 길다면 기존 것을 해제하고 다시 할당
void MyString::assign(const MyString& str) {
    if (str.string_length > string_length) {
        string_length = str.string_length;
        memory_capacity = string_length;
        delete[] string_content;
        string_content = new char[memory_capacity];

    } else {
        string_length = str.string_length;
    }
    for (int i=0; i!=string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
void MyString::assign(const char* str) {
    if (strlen(str) > string_length) {
        string_length = strlen(str);
        memory_capacity = string_length;
        delete[] string_content;
        string_content = new char[memory_capacity];
    } else {
        string_length = strlen(str);
    }
    for (int i=0; i!=string_length; i++) {
        string_content[i] = str[i];
    }
}
// 특정 위치에 문자 또는 문자열 삽입
MyString& MyString::insert(int loc, const MyString& str) {
    // 범위를 벗어나면 객체 리턴
    if (loc < 0 || loc > string_length) {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity) {
        // 메모리 공간을 미리 확보해서 공간을 희생하는 대신 속도를 높인다.
        if (memory_capacity * 2 > str.string_length + string_length) {
            memory_capacity *= 2;
        } else {
            memory_capacity = string_length + str.string_length;
        }
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        // loc 이전까지의 내용 복사
        int i;
        for (i=0; i<loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        // 새로운 내용 삽입
        for (int j=0; j != str.string_length; j++) {
            string_content[i+j] = str.string_content[j];
        }
        // loc 이후의 내용 복사
        for (;i<string_length;i++) {
            string_content[i + str.string_length] = prev_string_content[i];
        }

        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }
    // 동적 할당이 필요가 없는 경우
    for (int i= string_length-1; i>=loc; i--) {
        // 뒤로 밀기, 뒤에서부터 대입
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i=0; i< str.string_length; i++) {
        string_content[i+loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // 지우려는 문자의 갯수가 out of range일 경우
    if ((string_length-loc) < num) return *this;
    if (loc < 0 || num < 0 || loc > string_length) return *this; 

    for (int i = loc+num; i < string_length; i++) {
        string_content[i-num] = string_content[i];
    }
    string_length -= num;
    return *this;
}
// 문자열 위치 찾기
int MyString::find(int find_from, const MyString& str) const {
    int i,j;
    if (str.string_length == 0) return -1;
    for (i=find_from; i<= string_length - str.string_length; i++) {
        for (j=0; j < str.string_length; j++) {
            // 일치하지 않는 char 발견시 roop break;
            if (string_content[i+j] != str.string_content[j]) break;
        }
        // j == str.string_length이라는 뜻은 반복문을 break없이 돌고 나왔다는 뜻 
        if (j== str.string_length) return i;
    }

    return -1; // 찾지 못함
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
// 문자열 비교 함수
int MyString::compare(const MyString& str) const {
    // 1, 0 , -1을 리턴
    // 1은 (*this)가 사전식으로 더 뒤에 온다는 의미
    // 0은 두 문자열이 같다는 의미
    // -1은 (*this)가 사전식으로 더 앞에 온다는 의미
    for (int i=0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i]) 
            return 1;
        else if (string_content[i] < str.string_content[i]) 
            return -1;
    }
    // 여기까지 했는데 리턴이 되지 않았다면 앞 부분까지 모두 똑같다는 뜻이다. 만일 문자열의 길이가 같다면 두 문자열은 아예 같은 문자열이다.
    if (string_length == str.string_length) return 0;
    else if (string_length > str.string_length) return 1;

    return -1;
}

int main() {
    MyString str1("abcdef");
    MyString str2("abcde");

    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
    return 0;
}
