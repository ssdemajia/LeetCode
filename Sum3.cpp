#include "inc.h"
//leetcode 15 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int> > result;
       if (nums.size() < 3) return result;
       int right,left,obj;
       for (int i = 0; i < nums.size(); i++)
       {
           if (nums[i] > 0) continue;//如果第一个数是大于0，则不考虑
           if(i-1 >= 0 && nums[i] == nums[i-1]) continue;//如果是一样的第一个数，不考虑
           obj = -nums[i];//第二第三数的和是第一个数的相反数
           left = i+1;//从下一个数考虑
           right = nums.size()-1;

           while (left < right)
           {
               if (nums[left]+nums[right] == obj)//如果满足等式则加入到结果中
               {
                   result.push_back({nums[i], nums[left], nums[right]});
                   int front = left;//第二个数的索引
                   int end = right;//第三个数的索引
                   while(left < right && nums[front] == nums[left]) left++;//跳过相同的数
                   while(right > left && nums[end] == nums[right]) right--;
               }
               else if (nums[left]+nums[right]>obj)//如果大于则将第三个数变小
               {
                   right--;
               }
               else    left++;

           }

       }
       return result;
   }
};
int main(int argc, char const *argv[]) {
    vector<int> nums = {-2,0,0,2,2};
    Solution so;
    displayVec2d(so.threeSum(nums));
    vector<int>nums2 = {1,-1,-1,0};
    displayVec2d(so.threeSum(nums2));
    vector<int>nums3 = {-1,0,1,2,-1,-4};
    displayVec2d(so.threeSum(nums3));
    vector<int>nums4 = {1,1,-2};
    displayVec2d(so.threeSum(nums4));
    return 0;
}
