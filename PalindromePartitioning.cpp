#include "inc.h"
//131. Palindrome Partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        help(result, cur, s, 0);
        return result;
    }
    void help(vector<vector<string>> &result, vector<string> &cur,
        string &s, int index) {
           // displayVec(cur);

        if (index == s.size()) {
            result.push_back(cur);
            return;
        }
        for (int i = index+1; i <= s.size(); i++) {
            string temp = s.substr(index, i-index);
            //cout << "temp:" << temp <<", index:"<<index<<", i:"<<i<<endl;
            if (check(temp)){
                cur.push_back(temp);
                help(result, cur, s, i);
                cur.pop_back();
            }
        }
    }
    bool check(string s){//检查是否是回文
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (s[i] == s[j]){
                i++;j--;
            }else{
                return false;
            }
        }
        return true;
    }
};
int main() {
    string s = "aaba";
    Solution so;
    // if (so.check("a"))cout<<"Yes!"<<endl;//用于测试检验回文功能的函数
    // else  cout<<"No!!"<<endl;
    displayVec2d(so.partition(s));
    return 0;
}