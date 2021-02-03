#include <iostream>
#include <string.h>

class string {
    char *str;
    int len;

    public:
    string(char c, int n); // 문자 c가 n개 있는 문자열로 정의
    string(const char *s);
    string(const string &s); // 복사 생성자
    ~string();

    void add_string(const string &s); // str 뒤에 s를 붙인다.
    void copy_string(const string &s); // str 뒤에 s를 복사한다.
    int strlen(); // 문자열 길이 리턴
};

string::string(char c, int n){
    char s[n];
    for (int i=0; i < sizeof(s); i++ ) {
        s[i] = c;
    }
    str = s;
    len = sizeof(s);
}
string::string(const char *s) {
    strcpy(str, s);
    len = strlen(s);
}
string::string(const string &s) {
    len = s.len;
    str = s.str;
}
