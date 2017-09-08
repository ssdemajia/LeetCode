#include "inc.h"
// 343. Integer Break
class Solution {
public:
    int integerBreak2(int n) {//使用dp来保存中间状态，即n可以由几个数组合构成
        vector<int> dp(n+1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j =1; j < i; j++) {
                dp[i] = max({dp[i], dp[j] * (i-j), j*(i-j)});
            }
        }
        displayVec(dp);
        return dp[n];
    }

/*
*   n可以构成为 2*(n-2) 或 3*(n-3), 因为 2*2*2 < 3*3，所以先把尽可能多的3找到，即n/3-1,之所以-1，因为这样剩余的情况为
    4，3，2
*/
    int integerBreak(int n) {
        if (n <= 2) return 1;
        if (n == 3) return 2;
        if (n%3 == 0) return pow(3, n/3);//n由3+3+3+3+...+3组成的情况
        if (n%3 == 1) return pow(3, n/3-1)*4;//n由2+2+3+3+...+3组成
        return pow(3, n/3)*2;//n由2+3+3+...+3组成
    }

};
int main() {
    Solution so;
    cout << so.integerBreak(5) << endl;
    return 0;
}