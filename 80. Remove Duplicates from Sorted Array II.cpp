#include "inc.h"
//80. Remove Duplicates from Sorted Array II
class Solution {
    /* 
    思路：使用map来保存每个数字的次数
    */
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        //vector<int> result;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] <2){
                nums[index++] = nums[i];
                m[nums[i]]++;
            }
        }
        return index;
    }
};
int main() {
    vector<int> nums = {1,1,1,2,2,3,3,3};
    Solution so;
    cout << so.removeDuplicates(nums) << endl;
    displayVec(nums);
    return 0;
}