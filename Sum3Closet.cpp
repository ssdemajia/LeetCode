#include "inc.h"
//16. 3Sum Closest
class Solution {
public:
    int abs(int x){
        return x<0?-x:x;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int imin = INT32_MAX;
        int result = 0;
        int right,left,obj;
        for (int i = 0; i < nums.size(); i++)
        {
            obj = target-nums[i];
            left = i+1;
            right = nums.size()-1;

            while (left < right)
            {
                int temp = nums[left]+nums[right];
                if (abs(temp - obj) < imin)
                {
                    cout << i << ","<<left<<","<<right<<"   imin:"<<imin<<"  temp:"<<temp<<"  nums[i]"<<nums[i]<<endl;
                    imin = abs(temp-obj);

                    result = temp+nums[i];

                }
                if (temp < obj) left++;
                else right--;
            }

        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {2,0,0,-2,-2,1};
    Solution so;
    cout << so.threeSumClosest(v, 1) << endl;;
    return 0;
}
