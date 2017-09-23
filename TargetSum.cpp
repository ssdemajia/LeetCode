#include "inc.h"
//494. Target Sum
class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int S) {
        sort(nums.begin(), nums.end());
        return helper(nums.size()-1, 0, S, nums);
    }
    int helper(int index, int sum, int target, vector<int>& nums) {
        cout <<"index:"<< index << ", sum:"<<sum << " test:"<<abs(sum-target)<<endl;
        if (index == -1) {
            if (sum == target) return 1;
            else return 0;
        }
        return helper(index-1, sum+nums[index], target, nums) +
               helper(index-1, sum-nums[index], target, nums);
    }
/*
动态规划的方法
目标是由nums中的一些正数Positive加上一些负数negative组成，
Positive - Negative = Target
其中Positive + Negative = Sum of Nums
将Negative移到等式右边，再在两边同时加上Positive，2×Positive = Target + Negative + Positive
得2*Positive = Target + Sum of Nums
Positive = (Target + SumOfNums) / 2;故Target + SumOfNums必须是偶数

*/
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((S+sum)%2==1 || sum < S || -sum > S) return 0;//必须满足要求-S<sum<S
        int positive = (S+sum)/2;
        vector<int> dp(positive+1, 0);
        dp[0] = 1;
        for (int num : nums) {//求nums有多少了子序列能够组合positive
            for (int i = positive; i >= num; i--) {
                dp[i] += dp[i-num];
            }
            displayVec(dp);
        }

        return dp[positive];
    }
};
int main() {
    Solution so;
    vector<int> nums = {1, 1, 4, 1, 1};
    cout << so.findTargetSumWays(nums, 6) << endl;
    return 0;
}