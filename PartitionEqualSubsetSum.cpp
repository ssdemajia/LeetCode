#include "inc.h"
//416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1 || nums.size() < 2) return false;
        
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        displayVec(dp);
        return dp[target] != 0;
    }
};
int main() {
    vector<int> nums1 = {1,5,11,5};//1,5,5   11
    vector<int> nums2 = {3,3,3,4,5};//3,3,3   4,5
    vector<int> nums = {1,1,1,1};
    Solution so;
    if (so.canPartition(nums)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}