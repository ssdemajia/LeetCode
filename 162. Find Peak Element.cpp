#include "inc.h"
//162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i]<<endl;
            if (i == 0 && nums[1] < nums[0]) return 0;
            else if (i == nums.size()-1 && nums[nums.size()-2] < nums[nums.size()-1]) return nums.size()-1;
            else if (i > 0 && i < nums.size()-1 && nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return -1;
    }
};
int main() {
    Solution so;
    vector<int> nums = {1,2,3,4,1,2,1,2,4};
    vector<int> nums1 = {-2147483648};
    cout << so.findPeakElement(nums1) << endl;
    return 0;
}