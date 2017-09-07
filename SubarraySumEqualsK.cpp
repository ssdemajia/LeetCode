#include "inc.h"
//560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> record;//储存key这么多子序列和的个数
        int sum = 0;//累加值
        int result = 0;
        for (int i : nums) {
            sum+=i;
            result += record[sum-k];
            record[sum]++;
        }
        return result;
    }
};
int main() {
    Solution so;
    vector<int> nums2 = {1,2,1,2,1};//k = 3
    vector<int> nums3 = {1,2,1,3,1};//k=3
    vector<int> nums = {-1, -1, 1};//k=0
    cout << so.subarraySum(nums,0)<<endl;
    return 0;
}