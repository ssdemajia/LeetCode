#include "inc.h"
//174. Dungeon Game
class Solution {
public:
    /*
    思路：有可能会出现一开始就是一连串负数，最后几个正数，使得负值的下限会很低(这个思路不对)
    思路2：从最右下开始，dp的这个点代表能够到这个点至少要有多少血
    */
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //displayVec2d(dungeon);
        //cout << "----------------------" << endl;
        int M = dungeon.size();//行
        int N = dungeon[0].size();//列
        vector<vector<int>> dp(M, vector<int>(N, 0));

        dp[M-1][N-1] = dungeon[M-1][N-1]>0?0:dungeon[M-1][N-1];
        for (int i = M-2; i >= 0; i--) {//最后一列
            dp[i][N-1] = min(dp[i+1][N-1] + dungeon[i][N-1], 0);
        }
        for (int i = N-2; i >= 0; i--) {
            dp[M-1][i] = min(dp[M-1][i+1] + dungeon[M-1][i], 0);
        }
        displayVec2d(dp);
        cout << "----------------------" << endl;
        for (int i = M-2; i>=0; i--) {
            for (int j = N-2; j>=0; j--) {
                dp[i][j] = max({dp[i+1][j]+dungeon[i][j], dp[i][j+1]+dungeon[i][j]});//每次找到需要血量最少的路径
                dp[i][j] = min(dp[i][j], 0);//如果得到是一个正的血量，那么表示这个节点之后都不需要额外的血，后面的路径就能满足血量需求
            }
        }
        displayVec2d(dp);
        cout << "----------------------" << endl;
        return dp[0][0]<0?abs(dp[0][0])+1:1;//如果最后还是血不够，这表示最少初始血量，如果是正数那么就不需要额外的血量，除了一开始的血量1
    }
};
int main() {
    vector<vector<int>> d = {//7
        {-2, -3, 3},
        {-5,-10, 1},
        {10, 30, -5}
    };
    vector<vector<int>> d1 = {//7
        {-2, -5, 4},
        {-1, -7, 1},
        { 2,  1, 0}
    };
    vector<vector<int>> d2 = {
        {1,-4,5,-99},
        {2,-2,-2,-1}
    };

    Solution so;
    cout << so.calculateMinimumHP(d2) << endl;
    return 0;
}
