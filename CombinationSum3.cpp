#include "inc.h"
//Leetcode 216
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        std::vector<int> can;
        for (int i = 1; i < n && i < 10; i++) {
            can.push_back(i);
        }
        //displayVec(can);
        vector<int> temp;
        helper(result, can, temp, n, 0, k);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> &can,
        vector<int> &cur, int target, int start, int wid)
    {
        if (target == 0 && cur.size() == wid) {
            result.push_back(cur);
            return;
        }
        if (cur.size()>wid) return;
        if (target < 0) return;
        for (int i = start; i < can.size(); i++) {
            cur.push_back(can[i]);
            helper(result, can, cur, target-can[i], i+1,wid);
            cur.pop_back();
        }
    }
};
int main(int argc, char const *argv[]) {

    int k = 2,n=18;
    Solution so;
    displayVec2d(so.combinationSum3(k, n));
    return 0;
}
