/*************************************************************************
    > File Name: SQLIST_QUESTION_CPP
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-24 下午4:34
 ************************************************************************/

#include <iostream>
#include "sqlist.h"

using namespace std;

/*
 * 王道论坛数据结构指导书
 *  2.2顺序表 综合应用题
 */


/*
 * 1.删除顺序表中最小元素，并返回元素值，将末尾元素填补空位
 */
template<class T>
int delete_min(sqlist<T> &arr) {
    if (arr.isEmpty()) {
        cout << "empty sqlist !!!" << endl;
        return 0;
    }
    int len = arr.length();
    int tmp = 0;
    for (int i = 1; i < len; ++i) {
        if (arr.arr[i] < arr.arr[tmp])
            tmp = i;
    }
    int t = arr.arr[tmp];
    arr.arr[tmp] = arr.arr[len - 1];
    arr.curr_size--;
    return t;
}

/*
 * 2.将顺序表所有元素逆置，要求空间复杂度为O(1)
 */

template<class T>
void reverse(sqlist<T> &list) {
    int len = list.curr_size;
    for (int i = 0; i <= len / 2; i++) {
        T tmp;
        tmp = list.arr[i];
        list.arr[i] = list.arr[len - i];
        list.arr[len - i] = tmp;
    }
}

/*
 *  3.删除长度为n的顺序表中所有值为x的元素，时间复杂度为O(n)，空间复杂的为O(1)
 */

template<class T>
void delete_x(sqlist<T> &list, T x) {
    int m = 0;
    for (int i = 0; i < list.curr_size; i++) {
        if (list.arr[i] != x) {
            list.arr[m] = list.arr[i];
            m++;
        }
    }
    list.curr_size = m;
}


int main() {
    cout << "Hello, World!" << endl;
    return 0;

}