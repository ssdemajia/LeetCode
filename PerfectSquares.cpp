#include "inc.h"
// 279. Perfect Squares
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            cout << "I:"<<i;
            for (int j = 1; j*j <= i; j++) {
                cout <<", j:"<<j;
                dp[i] = min(dp[i], dp[i-j*j]);
            }
            dp[i]++;
            cout << endl;
        }
        displayVec(dp);
        return dp[n];
    }
};
int main() {
    Solution so;
    cout << so.numSquares(13) << endl;
    return 0;
}