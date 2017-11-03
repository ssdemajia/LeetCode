#include "inc.h"
//162. Find Peak Element
class Solution {
public:
    /* 
    思路：第二个方法是二分思想，通过判断mid是处于上升还是下降周期，如果是上升那么
    缩小上升范围
    */
    int findPeakElement1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i]<<endl;
            if (i == 0 && nums[1] < nums[0]) return 0;
            else if (i == nums.size()-1 && nums[nums.size()-2] < nums[nums.size()-1]) return nums.size()-1;
            else if (i > 0 && i < nums.size()-1 && nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while (start < end) {
            cout << start << ", "<<end<<endl;
            int mid = (start+end)/2;
            if (nums[mid] > nums[mid+1]) {
                end = mid;
            }else{
                start = mid+1;
            }
            // if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            //     return mid;
        }
        return start;
    }
};
int main() {
    Solution so;
    vector<int> nums = {1,2,3,1};
    vector<int> nums1 = {-2147483648};
    cout << so.findPeakElement(nums) << endl;
    return 0;
}