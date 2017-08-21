#include "inc.h"
//661. Image Smoother
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(),0));
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                result[i][j] = cal(M, i,j);
            }
        }
        return result;
    }
    int cal(vector<vector<int>>& M, int row, int col) {
        int result = 0;
        int up = row-1, down = row+1, left = col-1, right = col+1;
        up = up<0?0:up;
        down = down>=M.size()?(M.size()-1):down;
        left = left<0?0:left;
        right = right>=M[0].size()?(M[0].size()-1):right;
        
        for (int i = up; i <= down; i++) {
            for (int j = left; j <= right; j++) {
                result+=M[i][j];
            }
        }
        result/=(right-left+1)*(down-up+1);
        return result;
    }
};
int main(){
    vector<vector<int>> M={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> M2 = {
        {7,8,9}
    };
    Solution so;
    //cout << so.cal(M, 1,1)<<endl;
    displayVec2d(so.imageSmoother(M2));
}