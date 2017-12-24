#include "inc.h"
class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {/* O(nlgm) */
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        int left = 0;
        int right = cols-1;
        int up = 0;
        int down = rows-1;
        // return helper(matrix, target, 0, down, 0, right);
        for (int i = 0; i < matrix.size(); i++) {
            if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end()) {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {/* O(n+m) */
        int rows = matrix.size();
        if (rows == 0)
            return false;
        while (matrix.size()>0 && matrix[matrix.size()-1][0] > target) {
            matrix.erase(matrix.end()-1);
        }
        while (matrix.size()>0 && matrix[matrix.size()-1].back() < target) {
            matrix.erase(matrix.end()-1);
        }
        int cols = matrix[0].size();
        int i = rows-1;
        int j = 0;/* in the buttom-left of matrix */
        while (i >= 0 && j < cols) {
            if (matrix[i][j] > target) {
                i--;
            }else if (matrix[i][j] < target) {
                j++;
            }else {
                return true;
            }
        }
        return false;
    }
};
int main(void) {
    vector<vector<int>> m = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution so;
    SS_ASSERT(so.searchMatrix(m, 15));
    return 0;   
}