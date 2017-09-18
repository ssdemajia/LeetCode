#include "inc.h"
#include <stack>
//20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c=='{' || c == '[') {
                st.push(c);
            }
            else if ((c == ')' || c == ']' || c == '}') && st.empty() ) {
                return false;
            }
            else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')){
                st.pop();
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
int main () {
    Solution so;
    string s = ")";
    if (so.isValid(s)) cout << "Yes!!" << endl;
    else cout << " No!!!" << endl;
    return 0;
}