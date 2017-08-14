#include "inc.h"
//leetcode 221 Maximal Square
class Solution {
public:
    //时间O(mn) 空间O(MN)
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size())  return 0;
        vector<vector<int> > dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        //dp[i][j]表示以i，j为右下角的正方形的边数
        int maaax = 0;
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                if (matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    if (dp[i][j] > maaax)
                    {
                        maaax = dp[i][j];
                    }
                }
                //取左上角和上方和左边的最小值作为共同边数的正方形
            }
        }
        return maaax*maaax;
    }
    int maximalSquare2(vector<vector<char>>& matrix) {
        if (!matrix.size())  return 0;
        vector<int> dp(matrix[0].size()+1,0);
        //displayVec(dp);
        //dp[i][j]表示以i，j为右下角的正方形的边数
        int maaax = 0, prev = 0, temp = 0;
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                temp = dp[j];//暂时保存临时的上一行的dp[i-1][j]用于下一个j迭代
                if (matrix[i-1][j-1] == '1')
                {
                    dp[j] = min(min(dp[j-1], dp[j]), prev)+1;
                    maaax = dp[j] > maaax ? dp[j] : maaax;
                }
                else
                {
                    dp[j] = 0;
                }
                prev = temp;
                //取左上角和上方和左边的最小值作为共同边数的正方形
            }
        }
        displayVec(dp);
        return maaax*maaax;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char> > v = {
        {'1','0','1','0','0','1','0'},
        {'1','0','1','1','1','1','0'},
        {'1','1','1','1','1','1','0'},
        {'1','0','0','1','0','1','0'},
        {'1','0','1','1','1','1','0'}
    };
    Solution so;
    cout << so.maximalSquare2(v)<<endl;;
    return 0;
}
