#include "inc.h"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ans = "";
        helper(n, 0, n, result, ans);
        return result;
    }
    void helper(int n, int i, int j, vector<string> &result, string ans)
    {
        //cout << "i:"<< i << ",j:"<<j<< ",ans:"<<ans<<endl;
        if (j == 0 && i == n)//当“）”用完时那么已经构建完成，并且左括号也用完
        {
            result.push_back(ans);
            return;
        }
        if (i < n)//左边的括号数量要小于n
        {
            helper(n, i+1, j, result, ans+"(");
        }
        if (j > 0 &&  n-j < i)//")"数量要小于"("的数量
        {
            helper(n, i, j-1, result, ans+")");
        }
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.generateParenthesis(3).size()<<endl;
    displayVec(so.generateParenthesis(3), "\n");
    return 0;
}
