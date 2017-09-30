#include "inc.h"
//516. Longest Palindromic Subsequence
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;//一个字符是长度为1的回文
        }
        for (int i = 1; i < s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {//i结尾，j开头的字符串
                 if (s[j] == s[i]) {//当开头和结尾字符串那么就对(j,i-1)、(j+1,i-1)、（j+1,i）比较    
                    dp[j][i] = max(dp[j][i-1],dp[j+1][i-1]+2);
                 }
                 else {
                     dp[j][i] = max({dp[j][i-1],dp[j+1][i-1], dp[j+1][i]});
                 }
            }
        }
        return dp[0].back();
    }
};
int main() {
    string s1 = "abbbca";//5
    string s2 = "baabab";//5
    string s3 = "bbbab";
    string s = "aabaaba";//6
    Solution so;
    cout << so.longestPalindromeSubseq(s) << endl;
    return 0;
}