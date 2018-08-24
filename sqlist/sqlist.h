/*************************************************************************
    > File Name: SQLIST_SQLIST_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-24 下午3:42
 ************************************************************************/

#ifndef SQLIST_SQLIST_H
#define SQLIST_SQLIST_H

#include <iostream>

template<class T>
class sqlist {
public:
    sqlist();

    sqlist(int s);

    ~sqlist();

    int length();                   //返回长度
    int find(T value);              //按值查找
    int getvalue(int i);            //按位置查找
    bool insert(int i, T value);     //插入
    //bool turn(int i, T value);       //修改值
    bool delet(int i);              //删除
    void print();                   //打印
    bool isEmpty();                 //空表判断
    void destroy();                 //销毁

    T *arr;
    int max_size;
    int curr_size;
};

template<class T>
sqlist<T>::sqlist() {
    max_size = 128;
    arr = new T[max_size];
    curr_size = 0;
}

template<class T>
sqlist<T>::sqlist(int s) {
    if (s > 128) {
        max_size = s + 128;
        arr = new T[max_size];
    } else {
        max_size = 128;
        arr = new T[max_size];
    }
    curr_size = s;
}

template<class T>
sqlist<T>::~sqlist() {
    destroy();
}

template<class T>
int sqlist<T>::length() {
    return curr_size;
}

template<class T>
int sqlist<T>::find(T value) {
    for (int i = 0; i < curr_size; i++) {
        if (arr[i] == value)
            return i + 1;
    }
    return 0;
}

template<class T>
int sqlist<T>::getvalue(int i) {
    if (i < 0 || i > curr_size) {
        std::cout << "error input !!!" << std::endl;
        return 0;
    }
    return arr[i - 1];
}

template<class T>
bool sqlist<T>::insert(int i, int value) {
    if (i < 0) {
        std::cout << "error input !!!" << std::endl;
        return false;
    }
    if (curr_size == max_size) {
        max_size += 128;
        T *new_arr = new T[max_size];
        for (int j = 0; j < i - 1; j++)
            new_arr[j] = arr[j];
        new_arr[i - 1] = value;
        for (int k = i; k < curr_size; k++)
            new_arr[k] = arr[k];
        return true;
    } else {
        for (int j = curr_size; j > i - 1; j--)
            arr[j] = arr[j - 1];
        arr[i - 1] = value;
        return true;
    }
}

template<class T>
bool sqlist<T>::delet(int i) {
    return false;
}

template<class T>
void sqlist<T>::print() {
    for (int i = 0; i < curr_size; ++i) {
        std::cout << getvalue(i) << " ";
    }
    std::cout << std::endl;
}

template<class T>
bool sqlist<T>::isEmpty() {
    if (curr_size == 0)
        return true;
    else return false;
}

template<class T>
void sqlist<T>::destroy() {

}
/*
template<class T>
bool sqlist<T>::turn(int i, T value) {
    if (i < 1 || i > curr_size)
        return false;
    arr[i - 1] = value;
    return true;
}
*/
#endif //SQLIST_SQLIST_H
