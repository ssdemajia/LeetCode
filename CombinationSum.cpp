#include "inc.h"
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int> > result;
        std::vector<int> temp;
        helper(result, candidates, temp, target, 0);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> &can,
        vector<int> &cur, int target, int start)
    {
        if (target == 0) {
            result.push_back(cur);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < can.size(); i++) {
            cur.push_back(can[i]);
            helper(result, can, cur, target-can[i], i);
            cur.pop_back();
        }
    }
};
int main(int argc, char const *argv[]) {
    vector<int> can = {3,2,7,6};//target = 7
    std::vector<int> can2 = {2,3,5};//target = 7
    Solution so;
    displayVec2d(so.combinationSum(can, 7));
    return 0;
}
