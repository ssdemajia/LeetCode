#include "inc.h"
//LeetCode 78. Subsets
class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int> > result;
    //     help(result, nums, vector<int>());
    //     result.push_back(vector<int>());
    //     return result;
    // }
    // void help(vector<vector<int> > &result, vector<int> nums, vector<int> temp) {
    //     if (nums.size() == 0) {
    //         return;
    //     }

    //     while (nums.size() > 0) {
    //         temp.push_back(nums[0]);
    //         result.push_back(temp);
    //         nums.erase(nums.begin());
    //         help(result, nums, temp);
    //         temp.pop_back();
    //     }
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        help(result, nums, temp, 0);
        result.push_back(vector<int>());
        return result;
    }
    void help(vector<vector<int> > &result, vector<int> &nums, vector<int> &temp, int index) {
        if (index == nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            result.push_back(temp);
            help(result, nums, temp, i+1);//使用i+1跳过上一个循环的位置
            temp.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> nums = {1,2,3};
    displayVec2d(so.subsets(nums));
    return 0;
}