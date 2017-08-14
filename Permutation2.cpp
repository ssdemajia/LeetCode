#include "inc.h"
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        helper(result, nums, 0);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> nums, int index) {
        //displayVec(nums);
        if (index == nums.size())
        {
            //displayVec(nums);
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            //if (i!=index && nums[i] == nums[index]) continue;
            if (i!=index && nums[i] == nums[i-1]) continue;
            swap(nums[i], nums[index]);
            displayVec(nums);
            helper(result, nums, index+1);
        }
        cout << "----------------------------" << endl;
    }
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    vector<int> nums1 = {1,2,1};
    vector<int> nums = {0,1,0,0,9};
    displayVec2d(so.permuteUnique(nums));
    return 0;
}
