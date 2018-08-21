/*************************************************************************
    > File Name: STRING_STRING_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21 下午3:40
 ************************************************************************/

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>
#include <string.h>

class String {
private:
    char *s;
    int size;

public:
    String();                                    //默认构造函数,用于创建空字符串
    ~String();                                   //析构函数
    String(const char *const cstr);                 //构造函数,带一个参数用来初始化字符串
    String(const String &rs);                    //复制构造函数,默认是浅层复制,需重载
    char &operator[](unsigned int length);       //重载下标运算符[]
    char operator[](unsigned int length) const;   //重载下标运算符[](const版本)
    String &operator=(const String &rs);         //重载复制运算符=，用于两个字符串之间的赋值
    String operator+(const String &rs);          //重载加法运算符+
    String operator+=(const String &rs);                                //重载组合运算符+=
    friend std::ostream &operator<<(std::ostream &output, const String &str);    //重载输出流运算符<<
    friend std::istream &operator>>(std::istream &input, String &str);            //重载输入流运算符>>
    friend bool operator<(const String &str1, const String &str2);        //重载小于运算符<
    friend bool operator>(const String &str1, const String &str2);        //重载大于运算符>
    friend bool operator==(const String &str1, const String &str2);       //重载等于运算符==
    unsigned int getlen() const;                                           //获取字符串长度
    const char *getstr() const;                                             //获取字符串
    String substr(const int st, int count);

};

String::String() {
    s = new char[1];
    size = 0;
    s[0] = '\0';
}

String::~String() {
    delete[] s;
    size = 0;
}

String::String(const char *const cstr) {
    int i = 0;
    for (; *(cstr + i) != '\0'; i++);
    size = i;
    s = new char[size];
    for (int j = 0; j < size; j++)
        s[j] = *(cstr + j);
    s[size] = '\0';
}

String::String(const String &rs) {
    size = rs.getlen() + 1;
    s = new char[size];
    for (int j = 0; j < size; j++)
        s[j] = rs[j];
    s[size] = '\0';
}

char &String::operator[](unsigned int length) {
    return s[length];
}

char String::operator[](unsigned int length) const {
    return *(s + length);
}

String &String::operator=(const String &rs) {
    int si = rs.getlen();
    if (size < si) {
        delete[] s;
        size = si;
        s = new char[si + 1];
    }
    for (int j = 0; j < si + 1; j++)
        s[j] = rs[j];
    s[si + 1] = '\0';
    return *this;
}

String String::operator+(const String &rs) {
    int si = size + rs.getlen();
    char *new_ch = new char[si];
    for (int i = 0; i < size; i++)
        new_ch[i] = s[i];
    for (int j = size; j < si; ++j)
        new_ch[j] = rs[j - size];
    new_ch[si] = '\0';
    String new_str(new_ch);
    return new_str;
}

String String::operator+=(const String &rs) {
    *this = *this + rs;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const String &str) {
    output << str.s;
    return output;
}

std::istream &operator>>(std::istream &input, String &str) {
    input >> str.s;
    return input;
}

bool operator<(const String &str1, const String &str2) {
    int i;
    for (i = 0; str1.s[i] == str2.s[i]; i++)
        if (str1.s[i] == '\0' && str2.s[i] == '\0')
            return false;
    if (str1.s[i] < str2.s[i])
        return true;
    return false;
}

bool operator>(const String &str1, const String &str2) {
    int i;
    for (i = 0; str1.s[i] == str2.s[i]; i++)
        if (str1.s[i] == '\0' && str2.s[i] == '\0')
            return false;
    if (str1.s[i] > str2.s[i])
        return true;
    return false;
}

bool operator==(const String &str1, const String &str2) {
    int i;
    for (i = 0; str1.s[i] == str2.s[i]; i++)
        if (str1.s[i] == '\0' && str2.s[i] == '\0')
            return true;
    return false;
}

unsigned int String::getlen() const {
    return size;
}

const char *String::getstr() const {
    return s;
}

String String::substr(const int st, int count) {
    if(count>size-st)
        count=size-st;
    char new_s[count];
    for(int i=0;i<count;i++)
        new_s[i]=s[st+i];
    new_s[count]='\0';
    return String(new_s);
}

#endif //STRING_STRING_H
