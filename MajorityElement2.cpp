#include "inc.h"
//229. Majority Element II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;//最多可能有两个数是大于n/3的
        int PreA = 0, PreB = 1;//保存有可能大于n/3的那个数,preB要改为1，以防遇到[0,0,0,0,0]的情况
        int countA = 0, countB = 0;//保存这两个数的个数
        for (int i = 0; i < nums.size(); i++) {
            if (PreA == nums[i]) {
                countA++;
            }
            else if (PreB == nums[i]) {
                countB++;
            }
            else if (countA == 0) {//如果这A是减为0了，则需要重新换一个
                PreA = nums[i];
                countA = 1;
            }
            else if (countB == 0) {//如果b减为0，则改变
                PreB = nums[i];
                countB = 1;
            }
            else {//剩下的数的总数是小于1/3的，故在减去后将不会存在
                countA--;
                countB--;
            }
        } 
        cout << "countA:"<<countA<<" countB:"<<countB<<endl;
        cout << "preA:" << PreA << " preB:"<<PreB<<endl;
        countA = countB = 0;
        for (auto n: nums)
        {
            if (n == PreA) countA++;
            if (n == PreB) countB++;
        }
        if (countA > nums.size()/3) result.push_back(PreA);
        if (countB > nums.size()/3) result.push_back(PreB);
        return result;
    }
};
int main() {
    vector<int> nums1 = {1,2,1,4,3};
    vector<int> nums = {8,8,7,7,7};
    Solution so;
    displayVec(so.majorityElement(nums));
}