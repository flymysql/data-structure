/*************************************************************************
    > File Name: main.cpp
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21
 ************************************************************************/
#include <iostream>
#include "myString.h"
#include "KMP.h"
#include <string.h>

using namespace std;

int main() {
    String test("12345");
    string s;
    cin>>s;
    cout << test << endl << test.length() << endl;
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
    cout << test2.substr(5, 8) << endl;

    cout << endl << "_________test__________" << endl;
    String test4("wow! you are so beautiful !");
    String test5;
    cin >> test5;
    cout << test4 << endl << test5 << test5.length() << endl
         << kmp_find(test4, test5) << strstr(test4, test5);
    return 0;
}