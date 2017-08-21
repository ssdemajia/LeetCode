#include "inc.h"
//54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return vector<int>();
        int col = matrix[0].size();
        vector<int> result(row*col);
        int up = 0;//上边界
        int down = row-1;//下边界
        int left = 0;//左边界
        int right = col-1;//右边
        int k = 0;
        while (true) {
            for (int i = left; i <= right; i++) result[k++] = matrix[up][i];
            if (++up > down) break;//上边输入到result中

            for (int i = up; i <= down; i++) result[k++] = matrix[i][right];
            if (--right < left) break;

            for (int i = right; i >= left; i--) result[k++] = matrix[down][i];
            if (--down < up) break;

            for (int i = down; i >= up; i--) result[k++] = matrix[i][left];
            if (++left > right) break;
        }
        return result;
    }  
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> matrix2 = {
        {2,3}
    };
    vector<vector<int>> matrix3 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrix4 = {
        {1,5},
        {2,6},
        {3,7}
    };
    vector<vector<int>> matrix5 = {
        {2}
    };
    vector<vector<int>> matrix6 = {
        {2,5,8},
        {4,0,-1}
    };
    vector<vector<int>> matrix7 = {
        {1,  2, 3, 4, 5},
        {6,  7, 8, 9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    vector<vector<int>> matrix8 = {
        { 2, 3, 4},
        { 5, 6, 7},
        { 8, 9,10},
        {11,12,13},
        {14,15,16}
    };
    vector<vector<int>> matrix9;
    Solution so;
    displayVec(so.spiralOrder(matrix9));
    return 0;
}