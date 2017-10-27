#include "inc.h"
//137. Single Number II
/* 

思路是：将每一个位的数量计算出来保存，最后在循环一次将对3取余为1的位加到结果中
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> counts(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            for (int i = 0; i < 32; i++) {
                if (temp&1){
                    counts[i]++;
                }
                temp>>=1;
                if (!temp) break;
            }
        }
        displayVec(counts);
        int result = 0;
        int temp = 1;
        for (int i = 0; i < 32; i++) {
            if (counts[i] %3==1){
                result|=temp;
            }
            temp<<=1;
        }
        return result;
    }
};
int main() {
    vector<int> nums = {1,4,2,2,1,3,2,4,1,4};
    Solution so;
    cout << so.singleNumber(nums) << endl;
    return 0;
}