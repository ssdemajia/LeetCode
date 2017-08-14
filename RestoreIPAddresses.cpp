#include "inc.h"
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string cur;
        helper(result, s, cur, 0, 0);
        return result;
    }
    void helper(vector<string> &result, string &s, string cur, int index, int count) {
        if (count > 3) return;
        if (index == s.size() && count == 3) {
            result.push_back(cur);
            return;
        }
        if (index != 0) {//添加 . 到cur中，并且增加count，count用于计算cur中已存在的'.'个数
            cur+=".";
            count +=1;
        }
        for (int i = 1; i < 4; i++) {//分别分割一个，两个，三个的情况
            if (i+index > s.size()) break;//如果超过了原始字符串的大小则不必考虑
            string temp = string(s,index,i);
            if (i==3 && !checkThree(temp)) continue;
            if (!checkZero(temp)) break;//当前有0开头则直接结束循环
            helper(result, s, cur+temp, index+i, count);
        }
    }
    bool checkZero(string s)//用来检测如果s是06,007,00这种形式则返回false
    {
        if (s.size() == 1){return true;}//个位数都是true
        if (s[0] == '0') return false;//开头是0的形式
        return true;
    }
    bool checkThree(string s){
        int len = s.size();
        int num = 0;
        int degree = 1;
        for (int i = 0; i<len; i++) {
            num+=(s[len-i-1]-'0')*degree;
            degree*=10;
        }
        if (num <= 255) return true;
        return false;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    string s2 = "25525511135";
    string s3 = "16180172140";
    string s4 = "0000";
    string s0 = "16000";
    string s = "160600";
    displayVec(so.restoreIpAddresses(s), "\n");
    return 0;
}
