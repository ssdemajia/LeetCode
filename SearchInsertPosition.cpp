#include "inc.h"
//Leetcode 35
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size()-1;
        int mid = 0;
        while(i<=n)
        {
            cout << "i:"<<i<<",n:"<<n<<endl;

            mid = (i+n)/2;

            cout << "nums["<<mid<<"]:"<<nums[mid] << endl;

            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else if (nums[mid] > target)
            {
                n = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return i;
    }
};
int main(int argc, char const *argv[]) {
    std::vector<int> v = {1,2,3};
    Solution so;
    cout << so.searchInsert(v, 2) << endl;
    return 0;
}
