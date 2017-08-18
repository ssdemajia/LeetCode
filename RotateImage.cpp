#include "inc.h"
class Solution {
public:
    void rotate2(vector<vector<int>>& matrix) {//使用了辅助空间
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> result(col,vector<int>(row, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[j][col-i-1] = matrix[i][j];
            }
        }
        matrix = result;
    }
    void rotate(vector<vector<int>>& matrix) {//不使用辅助空间
        int row = matrix.size();
        int col = matrix[0].size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < row; i++) {
            for (int j = i; j < col; j++) {//j从i开始，因为只取上三角
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // void swap(int &a, int &b) {
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }
};
int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution so;
    so.rotate(matrix);
    displayVec2d(matrix);
    
    
    return 0;
}