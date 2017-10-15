#include "inc.h"
//696. Count Binary Substrings
class Solution {
public:
    int countBinarySubstrings1(string s) {//Brute force is error!!!
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i+1; j<s.size(); j++) {
                //cout << s.substr(i, j-i+1)<<endl;
                if (isBalance(s, i, j)) {
                    //cout <<"Balance:"<< s.substr(i, j-i+1)<<endl;
                    result++;
                }
            }
        }
        return result;
    }
    bool isBalance(string &s, int start, int end) {
        //cout << s.substr(start, end-start+1) << endl;
        char cstart = s[start];
        char cend = s[end];
        if (cstart == cend) return false;
        //int s_count = 0;
        //int e_count = 0;

        while(start <= end) {
            if (s[start] == cstart && s[end] == cend){
                start++;
                end--;
            }else {
                return false;
            }
        }
        return true;
    }
    int countBinarySubstrings2(string s) {//将连续的相同数化成数的块，空间O(n)
        vector<int> chars;
        int count = 1;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] != s[i+1]) {
                chars.push_back(count);
                count=1;
            }
            else count++;
        }
        chars.push_back(count);
        //displayVec(chars);
        int result = 0;
        for (int i = 0; i < chars.size()-1; i++) {
            result += min(chars[i], chars[i+1]);
        }
        return result;
    }
    int countBinarySubstrings(string s) {//将连续的相同数化成数的块，空间用O(1)
        vector<int> chars;
        int result = 0;
        int pre = -1;
        int count = 1;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] != s[i+1]) {
                if (pre == -1) pre = count;
                else {
                    result += min(pre, count);
                }
                count=1;
            }
            else count++;
        }
        result += min(pre,count);
        return result;
    }
};
int main (){
    Solution so;
    string s = "000111";//3
    string s1 = "00110011";//6
    string s2 = "00100";//2
    cout << so.countBinarySubstrings(s2) << endl;
    // if (so.isBalance(s, 0, 5)) cout << "Yes" << endl;
    // else cout << "No" << endl;
  
    return 0;
}