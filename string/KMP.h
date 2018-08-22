/*************************************************************************
    > File Name: STRING_KMP_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-22 上午10:47
 ************************************************************************/

#ifndef STRING_KMP_H
#define STRING_KMP_H

#include "myString.h"

//模式匹配朴素算法
int find_pat(String p, String t, const int start = 0) {
    int len_p = p.getlen(), len_t = t.getlen();
    for (int i = start, j = 0; i < len_p - len_t; i++) {
        for (j = 0; p[j] == t[j] && j < len_t; j++);
        if (j == len_t)
            return i;
    }
    return -1;
}

//求字符串特征向量
int *get_next(String p) {
    int j = 0, k = -1, len = p.getlen();
    int *next = new int[len];
    next[0] = -1;
    next[1] = 1;
    while (j < len) {
        while (k >= 0 && p[k] == p[j])
            k = next[k];
        k++;
        j++;
        if (p[k] == p[j])
            next[j] = next[k];
        else
            next[j] = k;
    }
    return next;
}

//KMP 模式匹配算法
int kmp_find(String p, String t, const int start = 0) {
    int len_p = p.getlen(), len_t = t.getlen();
    if (start > len_p - len_t)
        return -1;
    int i = start, j = 0;
    int *next = get_next(t);
    while (i < len_p && j < len_t) {
        if (j == -1 || p[i] == t[j])
            i++, j++;
        else
            j = next[j];
    }
    if (j >= len_t)
        return i - len_t;
    else return -1;
}

#endif //STRING_KMP_H
