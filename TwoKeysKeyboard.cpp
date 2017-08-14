#include "inc.h"
//leetcode 650
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,0);
        for (int i = 0; i < dp.size(); i++) dp[i] = i;
        dp[1] = 0;
        if (n <= 0) return 0;
        for (int i = 2; i <= n; i++){
            for (int j = 2; j*j <= i; j++){
                if (i % j == 0 && dp[i] >= dp[i/j]+dp[j])
                {
                    dp[i] = dp[i/j] + dp[j];
                }
            }
        }
        displayVec(dp);
        return dp[n];
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.minSteps(99) << endl;
    return 0;
}
