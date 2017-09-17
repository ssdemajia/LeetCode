#include "inc.h"
//264. Ugly Number II
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int index2 = 0;
        int index3 = 0; 
        int index5 = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(index2*2, index3*3, index5*5);
            if (dp[i] == index2*2) index2++;
            if (dp[i] == index3*3) index3++;
            if (dp[i] == index5*5) index5++;
        }
        return dp[n-1];
    }
};