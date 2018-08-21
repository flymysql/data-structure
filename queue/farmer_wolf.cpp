/*************************************************************************
    > File Name: QUEUE_FARMER_WOLF_CPP
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-21 上午10:55
 ************************************************************************/

#include <iostream>
#include <bitset>
#include <vector>
#include "linkQueue.h"
using namespace std;

/*
 * 农夫过河问题
•  问题抽象:“人狼羊菜”乘船过河
– 只有人能撑船,船只有两个位置(包括人)
– 狼羊、羊菜不能在没有人时共处
 * 用整数 status 表示上述四位二进制描述的状态
– 整数 0x08 表示的状态 1 0 0 0
– 整数 0x0F 表示的状态 1 1 1 1
 */
bool farmer(int status) { return ((status & 0x04) != 0); }

bool wolf(int status) { return ((status & 0x04) != 0); }

bool cabbage(int status) { return ((status & 0x02) != 0); }

bool goat(int status) { return ((status & 0x01) != 0); }

bool safe(const int s) {
    if (wolf(s) == goat(s) && farmer(s) != wolf(s))
        return false;
    if (goat(s) == cabbage(s) && farmer(s) != goat(s))
        return false;
    return true;
}

/*
 * – 用顺序表 route 的第 i 个元素记录状态i是否已被访问过
   – 若 route[i] 已被访问过,则在这个顺序表元素中记入前驱
      状态值; -1表示未被访问
   – route 的大小(长度)为 16
 */
void solve() {
    vector<int> route(16, -1);
    linkQueue<int> moveto;
    moveto.push(0x00);
    route[0] = 0;

    int status, new_status, movers;
    while (!moveto.isEmpty() && route[15] == -1) {
        //获得当前状态
        moveto.pop(status);
        //选择要过河的人物movers 0001~1000
        for (movers = 1; movers <= 8; movers <<= 1) {
            //要过桥的人物必须和农夫在同一侧
            if (farmer(status) == (bool) (status & movers)) {
                //过河后的新状态
                new_status = status ^ (0x08 | movers);
                //如果状态安全并且未到达过
                if (safe(new_status && route[new_status] == -1)) {
                    route[new_status] = status;
                    moveto.push(new_status);
                }
            }
        }
    }

    if (route[15] != -1) {
        cout << "the path is:" << endl;
        for (int s = 15; s >= 0; s = route[s]) {
            cout << bitset<sizeof(int)>(s) << endl;
            if (s == 0)break;
        }
    } else
        cout << "NO solution !" << endl;
}

int main() {
    solve();
    return 0;

}