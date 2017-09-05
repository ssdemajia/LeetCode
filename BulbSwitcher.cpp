#include "inc.h"
//319. Bulb Switcher
class Solution {
public:
    int bulbSwitch2(int n) {//Time limit error
        if (!n) return n;
        vector<bool> v(n+1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j%i == 0) {
                    v[j] = v[j]?false:true;
                }
            }
        }
        int result = 0;
        for (int i = 1; i <=n; i++) {
            if (v[i]) result++;
        }
        return result;
    } 
    int bulbSwitch(int n) {//因为一个数i的因子个数是奇数是那么最后的时候这个灯泡是打开的，其中如果i是完全平方，则它的因子数是奇数
        int result = 0;//统计n范围内的完全平方数的个数
        for (int i = 1; i*i <= n; i++) result++;
        return result;
    }
};
int main() {
    Solution so;
    cout << so.bulbSwitch(99999) << endl;
}