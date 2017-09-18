#include "inc.h"
//680. Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            }
            else {
                return helper(s, start, end-1) || helper(s, start+1, end);
            }
        }
        return true;
    }
    bool helper(string &s, int start, int end) {
        cout << "s:"<<s<<endl;
        while(start<= end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            }else {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution so;
    if (so.validPalindrome("abcbava")) cout << "Yes!!" << endl;
    else cout << " No!!!" << endl;
    return 0;
}