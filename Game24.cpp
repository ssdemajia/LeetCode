#include "inc.h"
//679. 24 Game
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<vector<int>> permutation;
        helper(permutation, nums, 0);
        for (vector<int> num : permutation) {
            if (check(num[0], num[1], num[2], num[3])) return true;
        }
        return false;
    }
    bool check(double a, double b, double c, double d) {
        if (check(a+b, c, d) || check(a-b, c, d) || check(a*b, c, d) || check(a/b, c, d)) {
            return true;
        }
        if (check(a, b+c, d) || check(a, b-c, d) || check(a, b*c, d) || check(a, b/c, d)) {
            return true;
        }
        if (check(a, b, c+d) || check(a, b, c-d) || check(a, b, c*d) || check(a, b, c/d)) {
            return true;
        }
        return false;
    }
    bool check(double a, double b, double c){
        if (check(a+b, c)|| check(a-b, c) || check(a*b, c) || check(a/b, c)) {
            return true;
        }
        if (check(a,b+c)|| check(a, b-c) || check(a, b/c) || check(a, b*c)) {
            return true;
        }
        return false;
    }
    bool check(double a, double b) {
        if (abs(a+b-24) < 0.0001 || abs(a/b-24)<0.0001 || abs(a*b-24)<0.0001 || abs(a-b-24)<0.0001){
            return true;
        }
        return false;
    }
    void helper(vector<vector<int>> & result, vector<int> & nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            //displayVec(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            helper(result, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};
int main() {
    Solution so;
    vector<int> nums = {8, 3, 1, 1};
    if (so.judgePoint24(nums)) {
        cout << "Yes!!"<<endl;
    }
    else cout << "No!!" <<endl;
    return 0;
}