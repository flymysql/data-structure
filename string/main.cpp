/*************************************************************************
    > File Name: main.cpp
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21
 ************************************************************************/
#include <iostream>
#include "myString.h"

using namespace std;

int main() {
    String test("12345");
    cout << test << endl << test.getlen() << endl;
    String test2;
    test2 = test;
    cout << test2 << endl;
    String test3("i love you");
    // cin>>test3;
    cout << test3 << endl;
    test2 += test3;
    for (int i = 0; test2[i] != '\0'; i++)
        cout << test2[i];

    cout << endl << (test2 < test3) << endl << (test2 == test3) << endl;
    cout<<test2.substr(5,8)<<endl;
    return 0;
}