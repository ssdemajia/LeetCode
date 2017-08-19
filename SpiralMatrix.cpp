#include "inc.h"
//54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution so;
    displayVec(so.spiralOrder(matrix));
    return 0;
}