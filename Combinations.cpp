#include "inc.h"
//77. Combinations
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> prepare;
        for(int i = 1; i <= n; i++) prepare.push_back(i);
        helper(result, prepare, vector<int>(), k);
        //displayVec2d(result);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> prepare, vector<int> temp, int k)
    {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        while(prepare.size() > 0) {
            int first = prepare[0];
            temp.push_back(first);
            prepare.erase(prepare.begin());
            helper(result, prepare, temp, k);
            temp.pop_back();
        }
    }
};
int main() {
    Solution so;
    displayVec2d(so.combine(4,2));
    return 0;
}