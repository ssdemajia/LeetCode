#include "inc.h"
//646. Maximum Length of Pair Chain
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // int start = INT_MAX; int end = INT_MIN;
        // for (int i = 0; i < pairs.size(); i++) {
        //     if (pairs[i][0] < start) start = pairs[i][0];
        //     if (pairs[i][1] > end) end = pairs[i][1];
        // }
        
        sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
            if (a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<int> dp(pairs.size(), 1);
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                int a = pairs[j][0];
                int b = pairs[j][1];
                dp[i] = max(dp[i], pairs[i][0] > b?dp[j]+1:0);
            }
        }
        displayVec(dp);
        return dp[pairs.size()-1];
    }
};
int main() {
    vector<vector<int>> pairs1=  {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    vector<vector<int>> pairs = {
        {1,2},
        {4,4},
        {2,3},
        {5,6}
    };
    Solution so;
    cout << so.findLongestChain(pairs)<<endl;
    return 0;
}