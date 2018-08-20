/*************************************************************************
    > File Name: STACK_STACK_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-20 下午12:33
 ************************************************************************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

template <class T>
class Stack{
public:                         // 栈的运算集
    void clear();               // 变为空栈
    bool push(const T item);    // item入栈，成功返回真，否则假
    bool pop(T& item);          // 返回栈顶内容并弹出，成功返回真，否则假
    bool top(T& item);          // 返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();             // 若栈已空返回真
    bool isFull();              // 若栈已满返回真
};

#endif //STACK_STACK_H
