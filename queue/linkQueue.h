/*************************************************************************
    > File Name: QUEUE_LINKQUEUE_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21 上午10:09
 ************************************************************************/

#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H

#include <iostream>
#include "Queue.h"
#include "../link/link.h"

using namespace std;

template<class T>
class linkQueue : public Queue<T> {
private:
    link<T> *head;
    link<T> *tail;
    int num;
public:
    linkQueue();

    ~linkQueue();

    void clear();                   // 变为空队列
    bool push(const T item);     // 将item插入队尾，成功则返回真，否则返回假
    bool pop(T &item);          // 返回队头元素并将其从队列中删除，成功则返回真
    bool getFront(T &item);         // 返回队头元素，但不删除，成功则返回真
    bool isEmpty();                 // 返回真，若队列已空
    bool isFull();                  // 返回真，若队列已满
};

template<class T>
linkQueue<T>::linkQueue() {
    head = NULL;
    tail = NULL;
    num = 0;
}

template<class T>
linkQueue<T>::~linkQueue() {
    clear();
}

template<class T>
void linkQueue<T>::clear() {
    head = NULL;
    tail = NULL;
    num = 0;
    link<T> *tmp=head,*other=NULL;
    while (tmp!=NULL){
        other=tmp;
        tmp=tmp->next;
        delete other;
    }
}

template<class T>
bool linkQueue<T>::push(const T item) {
    if (tail == NULL) {
        head = tail = new link<T>(item, NULL);
    }
    tail->next = new link<T>(item, NULL);
    tail = tail->next;
    num++;
    return true;
}

template<class T>
bool linkQueue<T>::pop(T &item) {
    if (tail==NULL)
        return false;
    item=head->data;
    link<T> *tmp=head;
    head=head->next;
    delete tmp;
    if(head==NULL)
        tail=NULL;
    num--;
    return true;
}

template<class T>
bool linkQueue<T>::getFront(T &item) {
    if(head==NULL)
        return false;
    item=head->data;
    return true;
}

template<class T>
bool linkQueue<T>::isEmpty() {
    if(num==0)
        return true;
    return false;
}

template<class T>
bool linkQueue<T>::isFull() {
    return false;
}

#endif //QUEUE_LINKQUEUE_H
