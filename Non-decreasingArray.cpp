#include "inc.h"
//665. Non-decreasing Array
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool hasChange = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {//主要考察三个数A,B,C, 已知B>C,所以要分为两种情况A>C,A<C
                if (hasChange) return false;
                else {
                    if (i-2 >= 0 && nums[i-2] > nums[i]) nums[i] = nums[i-1];//当
                    else nums[i-1] = nums[i];//A<C的情况，这种情况下前一个数变为
                }
                hasChange = true;
            }
        }
        return true;
    }
}; 
int main() {
    Solution so;
    vector<int> nums = {2,3,3,2,4};
    vector<int> nums2 = {1,5,2,3,6,5,7};
    vector<int> nums3 = {3,3,2,2};
    vector<int> nums4 = {4, 3,1};
    vector<int> nums5 = {1,2,5,3,3};
    vector<int> nums6 = {1,2,4,5,3};
    if (so.checkPossibility(nums)){
        cout << "yes"<<endl;
    }
}