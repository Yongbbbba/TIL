#pragma once

class MyString
{
public:
    // ������
    MyString(const char c); // �� ���ڸ� �־��� ��
    MyString(const char* str); // ���ڿ��� �־��� ��
    MyString(const MyString& str); // ���������
    // �Ҹ���
    ~MyString();
    // ���ڿ��� ������ִ� �Լ�(print, println)
    void print();
    void println();
    // ���ڿ� ���̸� �����ϴ� �Լ�(length) 
    int length();
    // ���ڿ� ���� �Լ�(assign)
    void assign(const MyString& str);
    void assign(const char* str);
    // ���ڿ� �޸� �Ҵ� �Լ�(reserve) �� ���� �Ҵ�� ũ�⸦ �˾ƿ��� �Լ� (capacity)
    void reserve(int n);
    int capacity();
    // Ư�� ��ġ�� ���ڸ� �����ϴ� �Լ�(at)
    char at(int idx);
    // Ư�� ��ġ�� Ư�� ���ڿ��� �����ϴ� �Լ�(insert)
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, char c);
    MyString& insert(int loc, const char* str);
    // Ư�� ��ġ�� Ư�� ������ ���ڸ� ����� �Լ�(erase)
    MyString& erase(int loc, int num);
    // Ư�� ��ġ�� �������� Ư�� ���ڿ��� �˻��ϴ� �Լ�(find)
    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;
    // �� ���ڿ��� ������ ���ϴ� �Լ�(compare)
    int compare(const MyString& str) const;

protected:
    char* string_content; // ���ڿ��� ����Ű�� ������
    int string_length;// ���ڿ� ����
    int memory_capacity;// ���ڿ��� �Ҵ��� �޸� ũ�� 
};