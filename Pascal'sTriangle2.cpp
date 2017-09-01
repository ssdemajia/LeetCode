#include "inc.h"
//119. Pascal's Triangle II
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for (int i = 1; i < rowIndex+1; i++) {//一共有rowIndex行
            for (int j = i/2; j > 0; j--) {
                result[j] = result[j] + result[j-1];//要从中间开始往前面迭代
            }
            for (int j = i-1; j > i/2; j--) {//开始把对称的部分填入
                result[j] = result[i-j];
            }
        }
        return result;
    }
};
int main () {
    Solution so;
    displayVec(so.getRow(3));
    return 0;
}