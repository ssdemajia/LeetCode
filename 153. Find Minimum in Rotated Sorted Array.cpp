#include "inc.h"
//153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    /* 
    思路：主要观察集中情况，
    第一种是这个区域是顺序递增的，那么直接返回第一个数。
    第二种是这个区域存在rotate，那么在分成两种情况
            （1）中间数大于最后的数，则最小的数在后半区域
            （2）中间的数小于最后的数，则最小的数在前半区域
    */
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if (end == start) return nums[start];
        int mid = 0;
        while (start<=end) {
            
            mid = (start+end)/2;
            
            if (nums[mid] > nums[end]) {
                start = mid+1;
            }else if (nums[mid] < nums[end]) {
                if (nums[start] < nums[mid]) {
                    return nums[start];
                }
                else {
                    end = mid;
                }
            }else {
                return nums[mid];
            }
        }
        return nums[mid];
    }
};
int main() {
    vector<int> nums = {1};
    Solution so;
    cout << so.findMin(nums) << endl;
    return 0;
}