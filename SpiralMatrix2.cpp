#include "inc.h"
//59. Spiral Matrix II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int col = n, row = n;
        vector<vector<int>> result(n, vector<int>(n,0));
        if (!n) return result;
        int k = 1;
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        while (up<=down && left <= right) {
            for(int i = left; i <= right; i++) result[up][i] = k++;//每次都是尽可能输出最多的，直到行尾
            up++;
            for (int i = up; i <= down; i++) result[i][right] = k++;
            right--;
            for (int i = right; i >= left; i--) result[down][i] = k++;
            down--;
            for (int i = down; i >= up; i--) result[i][left] = k++;
            left++;
        }
        return result;
    }
};
int main(){
    Solution so;
    displayVec2d(so.generateMatrix(0));
    return 0;
}