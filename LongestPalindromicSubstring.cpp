#include "inc.h"
//leetcode 5 
class Solution {
public:
    string longestPalindrome2(string s) {//暴力解法O(n^3)
        int len = s.size();
        int maxSize = 0;
        string result;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (isPalindrome(s, i, j)) {
                    if  (j-i > maxSize) {
                        result = s.substr(i, j-i);
                        maxSize = j-i;
                    }
                }
            }
        }
        return result;
    }
    bool isPalindrome(string s, int start, int end){
        int len = end - start;
        for (int i = 0; i < len/2; i++) {
            if (s[i+start] != s[end-i-1]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome3(string s) {//动态规划
        string result;
        int maxSize = 0;
        int len = s.size();
        if (len == 1) return s;
        vector<vector<int> > dp (len+1, vector<int>(len+1, INT_MAX));
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (helper(dp, s, i, j)) {
                    if (j - i + 1 > maxSize){
                        maxSize = j-i+1;
                        result = s.substr(i, maxSize);
                        //cout << result << endl;
                    }
                }
            }
        }
        return result;
    }
    bool helper(vector<vector<int> > &dp, string & s, int i, int j) {
        //cout << "i:"<< i<< " j:"<<j << endl;
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        if (i > j) return false;
        if (i == j) {
            dp[i][j] = true;
            return true;
        }
        else if (j == i+1 && s[i] == s[j]) {
            dp[i][j] = true;
            return true;
        }
        else if ((dp[i+1][j-1] || helper(dp,s,i+1,j-1)) && s[i] == s[j]) {
            dp[i][j] = true;
            return true;
        }
        return false;
    }

    string longestPalindrome(string s) {//
        int maxStart = 0;
        int maxSize = 0;
        int len = s.size();
        int start = 0;
        int end = 0;
        if (len == 1) return s;
        for (int i = 0; i < len;) {
            start=end=i;//start、end从中间开始向两边蔓延
            while(end+1<len && s[end] == s[end+1] ) end++;//将中间数是重复的数跳过
            //因为无论是aa还是aaa都是对称的
            i = end+1;//i变成end的下一个，此时考虑了对称，则下一个循环就不再考虑对称中的数了
            while(start > 0 && end+1 < len &&s[start-1] == s[end+1]) {
                start--;
                end++;
            }
            int size = end - start+1;
            if (size > maxSize){
                maxSize = size;
                maxStart = start;
                cout << "start:"<<start<<",end:"<<end<<endl;
            }

        }
        return s.substr(maxStart,maxSize);
    }
};
int main(int argc, char const *argv[]) {
    unordered_map<string, string> m = {
        {"babad", "bab"},
        {"cbbd", "bb"},
        {"abdcuiucdaaa","dcuiucd"},
        {"a","a"},
        {"ccc","ccc"}
    };
    Solution so;
    for (auto p = m.cbegin(); p != m.cend(); p++){
        string result = so.longestPalindrome(p->first);
        if (result != p->second){
            std::cout << "Oops! "<<p->first<<" is wrong!" <<result<< '\n';
        }else{
            std::cout << "Yeah! "<<p->first<<" is right!" << '\n';
        }
    }
    return 0;
}
