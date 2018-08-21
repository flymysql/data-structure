/*************************************************************************
    > File Name: QUEUE_ARRQUEUE_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21 上午9:36
 ************************************************************************/

#ifndef QUEUE_ARRQUEUE_H
#define QUEUE_ARRQUEUE_H

#include <iostream>
#include "Queue.h"

#define Default_size 100

template<class T>
class arrQueue : public Queue<T> {
private:
    int size;                       //队的长度
    int front;                      //队头
    int tail;                       //队尾
    T *arr;                         //存储数组
public:
    arrQueue(int s);

    ~arrQueue();

    void clear();                   // 变为空队列
    bool push(const T item);     // 将item插入队尾，成功则返回真，否则返回假
    bool pop(T &item);          // 返回队头元素并将其从队列中删除，成功则返回真
    bool getFront(T &item);         // 返回队头元素，但不删除，成功则返回真
    bool isEmpty();                 // 返回真，若队列已空
    bool isFull();                  // 返回真，若队列已满
};

template<class T>
arrQueue<T>::arrQueue(int s = Default_size) {
    size = s + 1;
    arr = new T[size];
    front = 0;
    tail = -1;
}

template<class T>
arrQueue<T>::~arrQueue() {
    delete[] arr;
}

template<class T>
void arrQueue<T>::clear() {
    front = tail + 1;
}

template<class T>
bool arrQueue<T>::push(const T item) {
    if (tail + 2 == front)
        return false;
    tail = (tail + 1) % size;
    arr[tail] = item;
}

template<class T>
bool arrQueue<T>::pop(T &item) {
    if (tail + 1 == front)
        return false;
    item = arr[front];
    front = (front + 1) / size;
}

template<class T>
bool arrQueue<T>::getFront(T &item) {
    if (tail + 1 == front)
        return false;
    item = arr[front];
    return true;
}

template<class T>
bool arrQueue<T>::isEmpty() {
    if (tail + 1 == front)
        return true;
    return false;
}

template<class T>
bool arrQueue<T>::isFull() {
    if(tail+2==front)
        return true;
    return false;
}

#endif //QUEUE_ARRQUEUE_H
