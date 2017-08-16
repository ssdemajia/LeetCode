#include "inc.h"
//LeetCode 90. Subsets
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        sort(nums.begin(), nums.end());//使用排序，将相同的排在一起
        help(result, nums, temp, 0);
        result.push_back(vector<int>());
        return result;
    }
    void help(vector<vector<int> > &result, vector<int> &nums, vector<int> &temp, int index) {
        if (index == nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i-1]) continue;//一样的数就不需要在展开了，直接跳过
            temp.push_back(nums[i]);
            result.push_back(temp);
            help(result, nums, temp, i+1);//使用i+1跳过上一个循环的位置
            temp.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> nums = {1,2,3,2};
    displayVec2d(so.subsetsWithDup(nums));
    return 0;
}