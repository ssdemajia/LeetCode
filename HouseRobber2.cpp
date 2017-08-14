#include "inc.h"
//leetcode 213
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = helper(nums);
        reverse(nums.begin(), nums.end());
        int b = helper(nums);
        return max(a,b);
    }
    int helper(vector<int> &nums)
    {
        if (nums.size() <=0) return 0;
        if (nums.size() == 1) return nums[0];
        std::vector<int> v(nums.size(),0);
        std::vector<bool> v2(nums.size(), false);//v2用来记录是否使用了第一个数
        v[0] = nums[0];
        v2[0] = true;
        v2[1] = nums[0]>nums[1]?true:false;
        v[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {

            if (i == nums.size()-1 && v2[i-2] == true)
            {
                v[i] = max(v[i-2], v[i-1]);
            }
            else
            {
                v[i] = max(v[i-2]+nums[i], v[i-1]);
                v2[i] = v[i-2]+nums[i] > v[i-1]?v2[i-2]:v2[i-1];
                //如果使用了第一个数那么需要把v2[i]改为true
            }
        }
        return v[nums.size()-1];
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {2,1};
    Solution so;
    cout << so.rob(v) << endl;
    return 0;
}
