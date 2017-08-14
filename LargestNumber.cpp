#include "inc.h"
//Leetcode 179 Largest Number
class Solution {
public:
    static bool compare( int  x,  int y){
        string sx = to_string(x);
        string sy = to_string(y);
        string a = sx + sy;
        string b = sy + sx;
        int len = a.size();
        for (int i = 0; i < len; i++) {//通过比较两个字符大小来排序
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        string result;
        if (All_zero(nums)) {
            return "0";
        }
        sort(nums.begin(), nums.end(), compare);
        for (int i = 0; i < nums.size(); i++){
            result+=to_string(nums[i]);
        }
        return result;
    }
    bool All_zero(std::vector<int>&nums){
        for (int i : nums){
            if (i){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> nums3 = {12,121};
    vector<int> nums4 = {121,12};
    vector<int> nums2 = {3, 30, 34, 5, 9};
    vector<int> nums1 = {5041,7233,8441,8543,6385,3510,7485,8082,2331,4285,1741,6090,5940,9375,1881,2398,8853,4536,5570,2602,670,3797,877,485,5293,2977,9745,6911,7724,6942,1018,5538,5975,814,8040,3729,8109,6632,7401,6251,9316,1160,3350,6454,169,9043,9985,9739,6648,8383,310,6228,9760,1091,2377,4596,4072,5725,5711,236,9743,9579,1136,707,4622,2247,230,6623,4310,1516,7388,1595,2204,1331,3109,4307,5117,6790,9996,3248,2877,7770,7156,6088,3034,3229,9354,6063,9388,2030,6176,3521,9438,3329,2533,2184,1247,7002,844,3161};
    std::vector<int> nums5 = {0,0};
    std::vector<int> nums6 = {0,0,0};
    std::vector<int> nums7 = {824,938,1399,5607,6973,5703,9609,4398,8247};
    std::vector<int> nums = {12,128};
    //"9609938824824769735703560743981399"
    displayVec(nums);
    //sort(nums.begin(), nums.end(), Solution::compare);
    //displayVec(nums);
    Solution so;
    cout << so.largestNumber(nums) << endl;
    return 0;
}
