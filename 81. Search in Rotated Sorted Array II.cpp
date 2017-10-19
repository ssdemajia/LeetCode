#include "inc.h"
//81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while(l<=r) {
            mid = (l+r)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[r]) {
                if (nums[mid] < target ||  nums[r] >= target) {
                    l = mid+1;
                }else {
                    r = mid-1;
                } 
            }else if (nums[r] == nums[mid]){
                r--;
            }
            else {
                if (nums[mid] < target && nums[r]>=target) {
                    l = mid+1;
                }else {
                    r = mid-1;
                }
            }
        }
        return false;
    }
};