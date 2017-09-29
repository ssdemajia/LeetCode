#include "inc.h"
// 55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return true;
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (m-1<0) return false;//如果从上一个结束点，不能到当前点，就can't jump
            m = max(m-1, nums[i]);//尽可能延长生命
        }     
        return true;
    }
};
int main() {
    Solution so;
    vector<int> nums1 = {3,2,1,0,4};
    vector<int> nums2 = {0,2,3};
    vector<int> nums = {1,0,2};
    if (so.canJump(nums1)) {
        cout << "Yes!" <<endl;
    }else cout << "No!" << endl;
    return 0;
}