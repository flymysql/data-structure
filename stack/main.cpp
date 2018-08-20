/*************************************************************************
    > File Name: main.cpp
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-20
 ************************************************************************/
#include <iostream>
#include "arrStack.h"
#include "linkStack.h"
using namespace std;

int main() {
    arrStack<int> arrStack1(20);
    linkStack<char> linkStack1;

    for(int i=0;i<10;i++){
        arrStack1.push(i+2000);
        linkStack1.push((char)(i+65));
    }
    int arr;
    char link;
    for(int i=0;i<11;i++){
        arrStack1.pop(arr);
        linkStack1.pop(link);
        cout<<arr<<endl<<link<<endl;
    }
    cout<<arrStack1.isEmpty()<<endl;
    return 0;
}