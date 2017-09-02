#include "inc.h"
//647. Palindromic Substrings
class Solution {
public:
    int countSubstrings2(string s) {//使用动态规划
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            int j;
            for(j = 0; j <= i; j++) {
                if (s[j] == s[i]) {
                    int start = j;
                    int end = i;
                    while(start <= end) {
                        if (s[start] == s[end]) {
                            start++;
                            end--;
                        }
                        else break;
                    }
                    if (start > end) {
                        dp[i]++;
                    } 
                }
            }
            if (i > 0) dp[i] += dp[i-1];
        }
        displayVec(dp);
        return dp[s.size()-1];
    }
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int left = i, right = i; left>=0 && right < s.size() && s[left] == s[right];left--, right++)
            {
                result++;
            } 
            for (int left = i, right = i+1; left>=0 && right < s.size() && s[left] == s[right];left--, right++) {
                result++;
            }
        }
        return result;
    }
};
int main () {
    Solution so;
    cout << so.countSubstrings("aaacaa") << endl;
}