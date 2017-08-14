#include "inc.h"
//Leetcode 33
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) index = i;
        return index;
    }
};
int main()
{
    vector<int> nums = {}
}
