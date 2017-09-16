#include "inc.h"
//120. Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = triangle[i].size()-1; j >=0; j--) {
                if (j == 0) dp[0] += triangle[i][0];
                else if (j == triangle[i].size()-1) dp[j] = dp[j-1] + triangle[i][j];
                else {
                    dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
                }
            }
            //displayVec(dp);
        }
        //displayVec(dp);
        int dpmin = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) {
            if (dp[i] < dpmin) dpmin = dp[i];
        }
        return dpmin;
    }
};
int main() {
    vector<vector<int>> t = {
        {-1},
        {2,3},
        {1,-1,-1}
    };
    Solution so;
    cout << so.minimumTotal(t) << endl;
    return 0;
}