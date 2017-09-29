#include "inc.h"
//45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {//Greedy algorithm
        if (nums.size() <= 1) return 0;
        int sum = nums[0];
        int Max = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size()-1; i++) {
            sum--;//sum表示当前可以走多远，每走一个格子，sum需要减一
            Max--;//用Max来表示当前位置可以走的最远距离，是相对距离
            Max = max(Max, nums[i]);//最远可以走的距离需要不断更新，每次都要最大的值            
            if (sum == 0) {//上一次的步数已经走完了，需要更新下一次要走多少
                sum = Max;
                count++;
            }
        }
        return count;
    }
};
int main() {
    vector<int> nums2 = {2,1};//1
    vector<int> nums1 = {2,3,2,1,2,4,1,4};//4
    vector<int> nums = {2,3,1,1,4};//2
    vector<int> nums0 = {1,2};//1
    Solution so;
    cout << so.jump(nums1) << endl;
    return 0;
}