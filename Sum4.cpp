#include "inc.h"
//Leetcode 18
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int i = 0; i < len; i++) {
            if (nums[i] == nums[i-1] && i-1 >= 0) continue;
            for (int j = i+1; j < len; j++) {
                if (nums[j] == nums[j-1] && j-1 > i) continue;
                int temp = target - nums[i] - nums[j];
                //cout << "temp:"<<temp<<endl;
                int start = j+1;
                int end = len-1;
                int preStart = INT_MAX;//b
                while(start < end) {
                    //displayVec(nums);
                    cout << "i:"<<i<<",j:"<<j<<",start:"<<start<<",end:"<<end<<",temp:"<<temp<<endl;
                    int sum = nums[start] + nums[end];
                    if (temp == sum) {
                        if (preStart!=nums[start]){
                            result.push_back({nums[i], nums[j],nums[start],nums[end]});
                            preStart = nums[start];
                        }
                        start++;
                        end--;

                    }else if (sum > temp) {
                        end--;
                    }else if (sum < temp){
                        start++;
                    }
                }
            }
        }


        return result;
    }
};
int main()
{
    vector<int> v = {1,0,-1,0,-2,2};//target = 0
    vector<int> v2 = {-3,-2,-1,0,0,1,2,3};//target = 0
    vector<int> v3 = {0,0,0,0};//target = 0
    vector<int> v4 = {-1,0,-5,-2,-2,-4,0,1,-2};//target = -9

    Solution so;
    displayVec2d(so.fourSum(v3,0));
}
