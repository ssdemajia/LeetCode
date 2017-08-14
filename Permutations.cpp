#include "inc.h"
//Leetcode 46
class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;

        helper(result, nums, 0);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int>&nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);//index表示当前这一位的索引值，交换这一位的数字与剩下的数字
            helper(result, nums, index+1);//下一位的index组合
            swap(nums[index], nums[i]);//需要将交换的位恢复
        }
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums = {1,2,3};
    Solution so;
    vector<vector<int> > result = so.permute(nums);
    displayVec2d(result);
    return 0;
}
