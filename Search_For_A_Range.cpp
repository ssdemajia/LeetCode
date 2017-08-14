#include "inc.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                start = mid;
                end = mid;
                while(start > 0 && nums[start-1] == nums[start]) start--;
                while(end < nums.size()-1 && nums[end] == nums[end+1]) end++;
                return {start,end};
            }
            else if (nums[mid] < target) {
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return {-1,-1};
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums = {1,2,2,3,3,3,4,4,5,6,6,6,6,7,7,7,8,8,8,8,9,9};//target = 8
    vector<int> nums2 = {2,2};//target = 2
    vector<int> nums3 = {0,0,1,2,2};//target = 2
    Solution so;
    displayVec(so.searchRange(nums3, 2));
    return 0;
}
