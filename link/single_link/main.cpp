/*************************************************************************
    > File Name: main.cpp
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-18
 ************************************************************************/
#include <iostream>
#include "linklist.h"

using namespace std;

int main() {
    linklist<int> linklist1;
    linklist1.append(1);
    linklist1.append(2);
    linklist1.append(3);
    linklist1.append(4);
    linklist1.insert(5, 6);

    cout << (bool) linklist1.isEmpty() << endl;
    cout << linklist1.length() << endl;
    int k;
    cout << linklist1.getPos(k, 3) << " " << k << endl;
    linklist1.getValue(3, k);
    cout << k << endl;
    linklist1.delet(2);
    linklist1.clear();
    linklist1.show();
    return 0;
}