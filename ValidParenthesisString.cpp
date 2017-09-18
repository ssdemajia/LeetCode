#include "inc.h"
#include <stack>
//678. Valid Parenthesis String
class Solution {
public:
    bool checkValidString2(string s) {//Time Limit Error
        if (s=="*" || s.size()==0) return true;
        stack<char> st;
        //st.push(s[0]);
        for (int i = 0; i < s.size(); i++) {
            //cout << "i:" << i<<endl;
            if (s[i] == '('){
                st.push(s[i]);
            }
            else if (s[i] == '*') {
                string temp1 = s;
                temp1[i] = '(';
                string temp2 = s;
                temp2[i] = ')';
                string temp3 = s.substr(0,i)+s.substr(i+1,s.size()-i);
                //cout << "temp1:"<<temp1<<", temp2:"<<temp2<<", temp3:"<<temp3<<endl; 
                return checkValidString(temp1) || checkValidString(temp2) || checkValidString(temp3);
            }
            else {
                if (st.empty()) return false;
                else {
                    st.pop();
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
    bool checkValidString(string s) {
        int low = 0;//将每一个*作为),low的数字表示这种情况下的'('数量
        int hight = 0;//对于*直接将其作为(
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                low++;
                hight++;
            }
            else if (s[i] == ')') {//遇到')'需要将'('的数量减少
                if (low > 0) {//有多余的'('
                    low--;
                }
                hight--;
            }
            else {//遇到*的情况
                if (low > 0) low--;//若low没有，则将其表示为empty string
                hight++;//将其作为(,故数量增加
            }
            if (hight < 0) return false;//说明')'太多了
        }
        return low == 0;//low大于0表示(太多了
    }
};
int main() {
    Solution so;
    string s = "(()*";
    string s2 = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    if (so.checkValidString(s2)) cout << "Yes!!" << endl;
    else cout << " No!!!" << endl;
    return 0;
}