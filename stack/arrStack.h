/*************************************************************************
    > File Name: STACK_ARRSTACK_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-20 下午12:35
 ************************************************************************/

#ifndef STACK_ARRSTACK_H
#define STACK_ARRSTACK_H

#include <iostream>
#include "Stack.h"

using namespace std;

template<class T>
class arrStack : public Stack <T>{
    int size;
    int Top;
    T *arr;
public:
    arrStack(int s) {
        size = s;
        Top = -1;
        arr = new T[size];
    }

    arrStack() {
        Top = -1;
    }

    ~arrStack() { delete[] arr; }

    void clear();               // 变为空栈
    bool push(const T item);    // item入栈，成功返回真，否则假
    bool pop(T &item);          // 返回栈顶内容并弹出，成功返回真，否则假
    bool top(T &item);          // 返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();             // 若栈已空返回真
    bool isFull();              // 若栈已满返回真
};

template<class T>
void arrStack<T>::clear() {
    Top = -1;
}

template<class T>
bool arrStack<T>::push(const T item) {
    if (Top == size - 1) {
        cout << "Overflow error !!!" << endl;
        return false;
    }
    arr[++Top] = item;
    return true;
}

template<class T>
bool arrStack<T>::pop(T &item) {
    if (Top == -1) {
        cout << "Underflow error !!!" << endl;
        return false;
    }
    item = arr[Top--];
    return true;
}

template<class T>
bool arrStack<T>::top(T &item) {
    if (Top == -1) {
        cout << "Underflow error !!!" << endl;
        return false;
    }
    item = arr[Top];
    return true;
}

template<class T>
bool arrStack<T>::isEmpty() {
    if(Top==-1)
        return true;
    else
        return false;
}

template<class T>
bool arrStack<T>::isFull() {
    if(Top=size-1)
        return true;
    else
        return false;
}

#endif //STACK_ARRSTACK_H
