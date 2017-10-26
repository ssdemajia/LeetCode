#include "inc.h"
//137. Single Number II
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[0]&=nums[i];
        }
        return nums[0];
    }
};
int main() {
    vector<int> nums = {1,4,2,2,1,3,2,4,1,4};
    Solution so;
    cout << so.singleNumber(nums) << endl;
    return 0;
}