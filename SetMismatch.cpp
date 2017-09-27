#include "inc.h"
//645. Set Mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> all(nums.size()+1,0);
        
        for (int i = 0; i < nums.size(); i++) {
            all[nums[i]]++;
        }
        int a,b;
        for (int i = 1; i < all.size(); i++) {
            if (all[i] == 0) {
                b = i;
            }
            if (all[i] == 2) {
                a = i;
            }
        }
        return {a,b};
    }
};
int main() {
    vector<int> nums = {2,2};
    Solution so;
    displayVec(so.findErrorNums(nums));
}