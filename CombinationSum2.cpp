#include "inc.h"
class Solution {
public:
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     std::vector<std::vector<int> > result;
    //     sort(candidates.begin(), candidates.end());
    //     //displayVec(candidates);
    //     std::vector<int> temp;
    //     unordered_map<int,bool> hasVisit;
    //     helper(hasVisit,result, candidates, temp, target, 0);
    //     return result;
    // }
    // void helper(unordered_map<int,bool> &hasVisit,vector<vector<int> > &result, vector<int> &can,
    //     vector<int> &cur, int target, int start)
    // {
    //     if (target == 0) {
    //         int sum = check(cur);
    //         //cout << "sum:"<<sum<<endl;
    //         if (hasVisit.count(sum)==0){
    //             result.push_back(cur);
    //             hasVisit[sum] = true;
    //         }
    //         return;
    //     }
    //     if (target < 0) return;
    //
    //     for (int i = start; i < can.size(); i++) {
    //         cur.push_back(can[i]);
    //         helper(hasVisit,result, can, cur, target-can[i], i+1);
    //         cur.pop_back();
    //     }
    // }
    // int check(std::vector<int> &v)
    // {
    //     int sum = 0;
    //     for(int i:v){
    //         sum*=10;
    //         sum+=i;
    //     }
    //     return sum;
    // }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int> > result;
        sort(candidates.begin(), candidates.end());
        std::vector<int> temp;
        helper(result, candidates, temp, target, 0);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> &can,
        vector<int> &cur, int target, int start)
    {
        if (target == 0) {
            result.push_back(cur);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < can.size(); i++) {
            if (i != start && can[i] == can[i-1]) continue;//剪去相同的根结点
            cur.push_back(can[i]);
            helper(result, can, cur, target-can[i], i+1);
            cur.pop_back();
        }
    }
};
int main(int argc, char const *argv[]) {
    vector<int> can = {10, 1, 2, 7, 6, 1, 5};//target = 8
    std::vector<int> can2 = {2,3,5};//target = 7
    Solution so;
    displayVec2d(so.combinationSum2(can, 8));
    return 0;
}
