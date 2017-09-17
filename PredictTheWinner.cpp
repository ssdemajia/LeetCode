#include "inc.h"
//486. Predict the Winner
class Solution {
public:
    bool PredictTheWinner1(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), INT_MIN));
        return helper(nums, 0, nums.size()-1, memo) >=0;
    }
    int helper(vector<int> &nums, int begin, int end, vector<vector<int>>& memo) {
        if (begin == end) return nums[begin];
        if (memo[begin][end] != INT_MIN) return memo[begin][end];
        int a = nums[begin] - helper(nums, begin+1, end, memo);//当前选的值减去剩余选择，得到的差值
        int b = nums[end] -  helper(nums, begin, end-1, memo);
        memo[begin][end] = max(a,b);
        return memo[begin][end];//当turn是-1时，需要改变
    }
    bool PredictTheWinner(vector<int>& nums) {//dp动态规划
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size(), 0));//start>begin时，没有最大值，为0
        // dp[i][j] = max(nums[i]+dp[i+1][j], nums[j]+dp[i][j-1]);
        for (int i = nums.size()-1; i>=0; i--) {//i相当于begin
            for (int j = i; j < nums.size(); j++) {//j相当于end，i==j时表示只有一个数字时
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        displayVec2d(dp);
        return dp[0][nums.size()-1]>=0;
    }
};
int main() {
    Solution so;
    vector<int> nums1 = {1,89,3};
    vector<int> nums2 = {1,5,233,7};
    vector<int> nums = {1,5,2};
    if (so.PredictTheWinner(nums2)) cout << "Yes!"<<endl;
    else cout << "No!"<<endl;
}