#include "inc.h"
//118. Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i+1, 1);
            result.push_back(temp);
            for (int j = 1; j < i/2+1; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
            for (int k = i/2+1; k < i; k++) {
                result[i][k] = result[i][i-k];
            }
            //cout << i << ":";
            //displayVec(result[i]);
        }
        return result;
    }
};
int main() {
    Solution so;
    displayVec2d(so.generate(1));
}