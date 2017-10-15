#include "inc.h"
#include <numeric>
//698. Partition to K Equal Sum Subsets
/* 
思路：主要是计算出分区的大小，也就是target，然后一共是k个target，每次计算一个target，
计算过程中的数使用过就hasUse[i] = true, 然后一直找到k-1个target时，剩余的也是target大小
这样返回true
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/k;
        if (nums[0] > target || sum%k != 0) return false;
        vector<bool> hasUse(nums.size(), false);
        
        return helper(nums, hasUse, 0, k-1, 0, target);
    }
    bool helper(vector<int>& nums, vector<bool>& hasUse, int sum, int k, int index, const int& target) {
        if (sum == target) {
            if (k == 1) return true;
            return helper(nums, hasUse, 0, k-1, 0, target);
        }
        for (int i = index; i < nums.size(); i++) {
            if (hasUse[i]) continue;
            if (sum+nums[i] > target) continue;
            hasUse[i] = true;
            if (helper(nums, hasUse, sum+nums[i], k, index+1, target)) return true;
            hasUse[i] = false;
        }
        return false;
    }
};
int main() {
    Solution so;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 2};//k=4
    vector<int> nums2 ={4, 3, 2, 3, 1, 2, 4};//k=4}
    vector<int> nums3 = {4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2};//13}
    if (so.canPartitionKSubsets(nums3, 13)) cout << "Yes" << "\n";
    else cout <<"No"<<"\n";
}
