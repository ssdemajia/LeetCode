#include "inc.h"
//73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes2(vector<vector<int>>& matrix) {//设置标记的方法不对
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < matrix.size(); k++) {
                        matrix[k][j] = matrix[k][j] == 0?0:INT_MIN;
                    }
                    for (int k = 0; k < matrix[i].size(); k++) {
                        matrix[i][k] = matrix[i][k] == 0?0:INT_MIN;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == INT_MIN) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {//使用最后一个0的所在行，来储存之前行的0元素的列
        int last_zero_row = -1;
        for (int i = matrix.size()-1; i >=0 && last_zero_row==-1; i--) {
            for (int j = matrix[i].size()-1; j>=0; j--) {//寻找最后一个0元素所在行
                if (matrix[i][j] == 0) {
                    last_zero_row = i;
                    break;
                }
            }
        }
        bool hasZero = false;
        if (last_zero_row == -1) return;//如果没有-1那么就不需要更改了
        for (int i = 0; i < last_zero_row; i++) {//遍历最后一个0元素之前的0元素
            hasZero = false;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[last_zero_row][j] = 0;//将0元素的列映射到Last_zero_row这一行
                    hasZero = true;//这一行有0元素
                }
            }
            if (hasZero){
                for (int k = 0; k < matrix[i].size(); k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int i = 0; i < matrix[last_zero_row].size(); i++) {//将标记为0的那些列，设为0
            if (matrix[last_zero_row][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;   
                }
            }
        }
        for (int i = 0; i < matrix[last_zero_row].size(); i++) {//将last_zero_row那一行填为0
            matrix[last_zero_row][i] = 0;
        }
    }
};
int main() {
    vector<vector<int>> matrix1 = {
        {1,2,3,0},
        {5,6,0,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> matrix2 = {
        {INT_MIN, INT_MAX, 0}
    };
    vector<vector<int>> matrix = {
        {0,0,0,5},
        {4,3,1,4},
        {0,1,1,4},
        {1,2,1,3},
        {0,0,1,1}
    };
    Solution so;
    so.setZeroes(matrix);
    displayVec2d(matrix);
    return 0;
}