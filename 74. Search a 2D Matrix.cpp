#include "inc.h"
//74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        r = matrix.size();
        if (r == 0) return false;
        c = matrix[0].size();
        int start = 0;
        int end = r*c-1;
        while (start <= end) {
            int mid = (start+end)/2;
            int num = matrix[from(mid).first][from(mid).second];
            if (num == target) {
                return true;
            }
            else if (num > target){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return false;
    }
    int to(const int &row, const int &col) {//行列换为数
        return row*c+col;
    }
    pair<int, int> from (const int& num) {
        return {num/c, num-num/c*c};
    }
private:
    int r;
    int c;
};
int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };
    vector<vector<int>> matrix2 = {
        {1,1}
    };
    Solution so;
    if (so.searchMatrix(matrix2, 2)) {
        TEST_PRINT("Yes")
    }
    else{
        TEST_PRINT("No")
    }   
    return 0;
}