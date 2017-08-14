#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Leetcode 152
//Find the contiguous subarray within an array
//(containing at least one number) which has the largest product.
class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int maxProduct(vector<int>& nums)
    {
        int r = nums[0];
        int imax = r;
        int imin = r;
        int result = r;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(imax, imin);//如果当前数小于零那么会使imax变小
                //使imin变大
            }
            //当前位置的最大值要么是上一次的结果乘以nums[i]或者是当前的nums[i]值
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            //最小值也是一样的，保存当前位置结尾的最小的值到imin中
            result = max(imax,result);
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {-2,2,3,1};
    Solution so;
    cout << so.maxProduct(v)<<endl;;
    return 0;
}
