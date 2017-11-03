#include <stack>
#include "inc.h"

//150. Evaluate Reverse Polish Notation
class Solution {
public:
    /* 
    思路：主要是用栈
    */
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> s;
        for (string token : tokens) {
            if (token == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }else if (token == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }else if (token == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }else if (token == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    Solution so;
    cout << so.evalRPN(tokens) << endl;
    return 0;
}