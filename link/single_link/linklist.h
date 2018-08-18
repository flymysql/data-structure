/*************************************************************************
    > File Name: LINK_LINKLIST_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-18 下午4:51
 ************************************************************************/

#ifndef LINK_LINKLIST_H
#define LINK_LINKLIST_H

#include <iostream>

using namespace std;

template<class T>
class link {
public:
    T data;
    link<T> *next;

    link(const T info, link<T> *nextnode = NULL) {
        data = info;
        next = nextnode;
    }

    link(link<T> *nextnode = NULL) {
        next = nextnode;
    }
};

template<class T>
class linklist {
private:
    link<T> *head, *tail;                       //头尾节点
    link<T> *setPos(const int p);               //第p个元素指针
public:
    linklist();

    linklist(int s);                            //构造函数
    ~linklist();                                //析构函数
    bool isEmpty();                             //判断链表是否为空
    void clear();                               //清空链表
    int length();                                //返回当前链表长度
    bool append(const T value);                 //表尾添加一个元素value
    bool insert(const int p, const T value);    //位置p插上一个元素
    bool delet(const int p);                    //删除位置p上的元素
    bool getValue(const int p, T &value);       //返回位置p上的元素值
    bool getPos(int &p, const T value);         //查找值为value为元素
    void show();                                //遍历链表
};

template<class T>
link<T> *linklist<T>::setPos(const int p) {
    link<T> *curr = head;
    for (int i = p - 1; i > 0; i--) {
        curr = curr->next;
        if (curr == NULL)return nullptr;
    }
    return curr;
}

template<class T>
linklist<T>::linklist() {
    head = new link<T>(0, NULL);
    head->next = NULL;
    tail = head;
}

template<class T>
linklist<T>::linklist(int s) {
    head = new link<T>(s, NULL);
    head->next = NULL;
    tail = head;
}

template<class T>
linklist<T>::~linklist() {

}

template<class T>
bool linklist<T>::isEmpty() {
    if (tail == head)return true;
    return false;
}

template<class T>
void linklist<T>::clear() {

}

template<class T>
int linklist<T>::length() {
    link<T> *curr = head;
    int i = 1;
    for (; curr->next != NULL; i++)
        curr = curr->next;
    return i;
}

template<class T>
bool linklist<T>::append(const T value) {
    link<T> *p, *q;
    p = tail;
    q = new link<T>(value, p->next);
    p->next = q;
    tail = q;
    return true;
}

template<class T>
bool linklist<T>::insert(const int p, const T value) {
    link<T> *m, *n;
    if ((m = setPos(p - 1)) == NULL) {
        cout << "非法插入点" << endl;
        return false;
    }
    n = new link<T>(value, m->next);
    m->next = n;
    if (m == tail)
        tail = n;
    return true;
}

template<class T>
bool linklist<T>::delet(const int p) {
    link<T> *m;
    if ((m = setPos(p - 1)) == NULL || m == tail) {
        cout << "非法删除点" << endl;
        return false;
    }
    if (m->next == tail) {
        tail = m;
        m->next = NULL;
    } else
        m->next = m->next->next;
    delete m->next;
}

template<class T>
bool linklist<T>::getValue(const int p, T &value) {
    link<T> *m;
    if ((m = setPos(p)) == NULL) {
        cout << "非法节点" << endl;
        return false;
    }
    value = m->data;
    return true;
}

template<class T>
bool linklist<T>::getPos(int &p, const T value) {
    link<T> *curr;
    curr = head;
    int i = 1;
    for (; curr != NULL; i++) {
        if (curr->data == value) {
            p = i;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template<class T>
void linklist<T>::show() {
    link<T> *curr;
    curr = head;
    for (; curr != NULL; curr = curr->next)
        cout << curr->data << endl;
}

#endif //LINK_LINKLIST_H
