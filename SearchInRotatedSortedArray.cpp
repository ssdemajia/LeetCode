#include "inc.h"
//Leetcode 33
/* 
思路：分成两个区域，有顺序的区域和rotate的区域
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            cout << "start:"<<start<<",mid:"<<mid<<",end:"<<end<<endl;
            if (nums[mid] == target) {
                return mid;
            }else if (nums[start] < nums[end]) {//有顺序的区域
                if (nums[mid] < target) {
                    start = mid+1;
                }else {
                    end = mid-1;
                }
            }else if (nums[start] > nums[end]) {//rotate的区域
                if (nums[start] > nums[mid] && nums[mid] <= nums[end]) {//判断rotate在前半部分还是后半部分
                    if (target <= nums[end] && nums[mid] < target) {
                        start = mid+1;
                    }else {
                        end = mid-1;
                    }
                }
                else if (nums[start] <= nums[mid]) {//rotate中枢在mid和end之间
                    if (target < nums[mid] && target >= nums[start]) {
                        end = mid-1;
                    }else {
                        start = mid+1;
                    }
                }
            }else if (start == end) return -1;
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {20,21,22,25,28,1,2,3,5,7,11,15,16,17,19};
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,1};
    Solution so;
    cout << so.search(nums2, 0) << endl;
    cout << so.search(nums, 19) << endl;
    return 0;
}
