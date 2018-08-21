/*************************************************************************
    > File Name: QUEUE_QUEUE_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21 上午9:34
 ************************************************************************/

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<class T>
class Queue {
public: // 队列的运算集
    void clear(); // 变为空队列
    bool push(const T item);

    // 将item插入队尾，成功则返回真，否则返回假
    bool pop(T &item);

    // 返回队头元素并将其从队列中删除，成功则返回真
    bool getFront(T &item);

    // 返回队头元素，但不删除，成功则返回真
    bool isEmpty(); // 返回真，若队列已空
    bool isFull(); // 返回真，若队列已满
};

#endif //QUEUE_QUEUE_H
