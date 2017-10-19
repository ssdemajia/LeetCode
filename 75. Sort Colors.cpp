#include "inc.h"
//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int index_r = -1;
        int index_b = nums.size();
        for (int i = 0; i < index_b;) {
            if (nums[i] == 0) {
                swap(nums[++index_r], nums[i]);//因为i是从左到右遍历的，所以index_r左边的都是0
                i++;//每次遍历后要求增加i
            }
            else if (nums[i] == 2){
                swap(nums[--index_b], nums[i]);
            }else {
                i++;
            }
        }
    }
};
int main() {
    vector<int> nums1 = {1,2,0,1,1,2,0,0,2};
    vector<int> nums = {0,0,1};
    Solution so;
    so.sortColors(nums);
    displayVec(nums);
    return 0;
}