#include "inc.h"
//leetcode 338
/*
Given a non negative integer number num.
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);//一共num+1个数
        int offset = 1;//偏移距
        for (size_t i = 1; i <= num; i++) {
            if (i == offset*2) offset <<=1;//每次到达2的指数位置，偏移也要乘以2
            result[i] = result[i-offset]+1;
        }
        return result;
    }
};
//num    0    1     /    2         3    /   4           5         6        7
//1‘bits 0    1     /    1         2    /   1           2         2        3
//dp     0  d[1-1]+1 d[2-2]+1  d[3-2]+1   d[4-4]+1  d[5-4]+1   d[6-4]+1
//offset     1               2                             4

int main(int argc, char const *argv[]) {
    Solution so;
    displayVec(so.countBits(5));
    return 0;
}
