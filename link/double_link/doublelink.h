/*************************************************************************
    > File Name: DOUBLE_LINK_DOUBLELINK_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-18 下午9:40
 ************************************************************************/

#ifndef DOUBLE_LINK_DOUBLELINK_H
#define DOUBLE_LINK_DOUBLELINK_H

#include <iostream>

using namespace std;

template<class T>
class Link {
public:
    T data;
    Link<T> *prev;
    Link<T> *next;

    Link(T info, Link<T> *pre_node, Link<T> *next_node) {
        data = info;
        prev = pre_node;
        next = next_node;
    }

    Link(Link<T> *pre_node, Link<T> *next_node) {
        prev = pre_node;
        next = next_node;
    }

    Link(T info) {
        data = info;
        prev = NULL;
        next = NULL;
    }
};

template<class T>
class doubleList {
private:
    Link<T> *head;
    Link<T> *tail;

    Link<T> *setPos(const int p);               //第p个元素指针
public:
    doubleList();

    doubleList(int s);

    ~doubleList();

    bool isEmpty();                             //判断链表是否为空
    void clear();                               //清空链表
    int length();                               //返回当前链表长度
    bool append(const T value);                 //表尾添加一个元素value
    bool insert(const int p, const T value);    //位置p插上一个元素
    bool delet(const int p);                    //删除位置p上的元素
    bool getValue(const int p, T &value);       //返回位置p上的元素值
    bool getPos(int &p, const T value);         //查找值为value为元素
    void show();                                //遍历链表

};

template<class T>
Link<T> *doubleList<T>::setPos(const int p) {
    if (p == -1)
        return head;
    Link<T> *q = head->next;
    for (int i = p; i > 0; i--)
        q = q->next;
    return q;
}

template<class T>
doubleList<T>::doubleList() {
    head = new Link<T>(0, NULL, NULL);
    tail = head;
}

template<class T>
doubleList<T>::doubleList(int s) {
    head = new Link<T>(1, NULL, NULL);
    head->next = new Link<T>(s, head, NULL);
    tail = head->next;
}

template<class T>
doubleList<T>::~doubleList() {

}

template<class T>
bool doubleList<T>::isEmpty() {
    if (head->data == 0)
        return true;
    return false;
}

template<class T>
void doubleList<T>::clear() {
    Link<T> *p, *q;
    p = head->next;
    q = p->next;
    while (p != NULL) {
        delete p;
        p = q;
        q = q->next;
    }
    head->data = 0;
    head->next = NULL;
    tail = head;
}

template<class T>
int doubleList<T>::length() {
    return head->data;
}

template<class T>
bool doubleList<T>::append(const T value) {
    Link<T> *p = new Link<T>(value, tail, NULL);
    tail->next = p;
    tail = p;
    head->data++;
    return true;
}

template<class T>
bool doubleList<T>::insert(const int p, const T value) {
    Link<T> *m = new Link<T>(value);
    Link<T> *n;
    if ((n = setPos(p - 1)) == NULL) {
        cout << "非法插入值" << endl;
        return false;
    }
    if (n == tail) {
        n->next = m;
        m->prev = n;
        tail = n;
    } else {
        n->next->prev = m;
        m->next = n->next;
        n->next = m;
        m->prev = n;
    }
    head->data++;
    return true;
}

template<class T>
bool doubleList<T>::delet(const int p) {
    Link<T> *m, *n;
    if ((m = setPos(p - 1)) == NULL || m == tail) {
        cout << "非法删除值" << endl;
        return false;
    }
    if (m->next == tail) {
        tail = m;
        tail->next = NULL;
        delete tail->next;
        head->data--;
        return true;
    }
    n = m->next;
    m->next = n->next;
    n->next->prev = m;
    delete n;
    head->data--;
    return true;
}

template<class T>
bool doubleList<T>::getValue(const int p, T &value) {
    Link<T> *m;
    if ((m = setPos(p)) == NULL) {
        cout << "越界" << endl;
        return false;
    }
    value = m->data;
    return true;
}

template<class T>
bool doubleList<T>::getPos(int &p, const T value) {
    Link<T> *curr;
    curr = head;
    int i = 0;
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
void doubleList<T>::show() {
    Link<T> *curr;
    curr = head->next;
    for (; curr != NULL; curr = curr->next)
        cout << curr->data << endl;
}


#endif //DOUBLE_LINK_DOUBLELINK_H
