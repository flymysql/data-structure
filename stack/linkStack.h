/*************************************************************************
    > File Name: STACK_LINKSTACK_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-20 下午2:16
 ************************************************************************/

#ifndef STACK_LINKSTACK_H
#define STACK_LINKSTACK_H

#include <iostream>
#include "Stack.h"

using namespace std;

template<class T>
class link {
public:
    T data;
    link<T> *next;

    link(int s, link<T> *next_node = NULL) {
        data = s;
        next = next_node;
    }
    ~link();
};


template<class T>
class linkStack : public Stack<T> {
private:
    link<T> *Top;
    int num;
public:
    linkStack() {
        Top = NULL;
        num = 0;
    }

    ~linkStack();

    void clear();               // 变为空栈
    bool push(const T item);    // item入栈，成功返回真，否则假
    bool pop(T &item);          // 返回栈顶内容并弹出，成功返回真，否则假
    bool top(T &item);          // 返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();             // 若栈已空返回真
    bool isFull();              // 若栈已满返回真
};

template<class T>
linkStack<T>::~linkStack() {
    clear();
}

template<class T>
void linkStack<T>::clear() {
 /*   link<T> *curr = Top->next;
    link<T> *temp = curr->next;
    while (curr != NULL) {
//        delete curr;
        curr = temp;
        temp = temp->next;
    }
    num=0;
    Top = NULL;
    */
}

template<class T>
bool linkStack<T>::push(const T item) {
    Top = new link<T>(item, Top);
    num++;
    return true;
}

template<class T>
bool linkStack<T>::pop(T &item) {
    if(Top==NULL){
        cout<<"Underflow error !!!"<<endl;
        return false;
    }
    item = Top->data;
  //  link<T> *Tem = Top;
    Top = Top->next;
  //  delete Tem;
    num--;
    return true;
}

template<class T>
bool linkStack<T>::top(T &item) {
    if(Top==NULL){
        cout<<"Empty Stack !!!"<<endl;
        return false;
    }
    item = Top ->data;
    return true;
}

template<class T>
bool linkStack<T>::isEmpty() {
    if(num==0)
        return true;
    else
        return false;
}

template<class T>
bool linkStack<T>::isFull() {
    if(num>10000)
        cout<<"The stack item is over 10000 !"<<endl;
    return false;
}

#endif //STACK_LINKSTACK_H
