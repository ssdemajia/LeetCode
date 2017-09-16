#include "inc.h"
// 264. Ugly Number II
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 6) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int index2 = 0;//保存已经乘以2后的数组下一个数字
        int index3 = 0;//保存已经乘以2后的数组下一个数字
        int index5 = 0;//保存已经乘以2后的数组下一个数字
        //每个数都需要分别乘以2，3，5
        //使用min({dp[index2]*2, dp[index3]*3, dp[index5]*5});
        //来确定这一个数是之前哪个数乘以2，3，5所得，则增加2，3，5结尾的长度
        for (int i = 1; i <= n; i++){
            dp[i] = min({dp[index2]*2, dp[index3]*3, dp[index5]*5});
            if (dp[i] == dp[index2]*2) index2++;
            if (dp[i] == dp[index3]*3) index3++;
            if (dp[i] == dp[index5]*5) index5++;
        }
        //displayVec(dp);
        return dp[n-1];
    }
};
int main(){
    Solution so;

    cout << so.nthUglyNumber(12) << endl;
    return 0;
}