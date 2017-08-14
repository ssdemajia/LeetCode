#include "inc.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int arr[m][n];
        arr[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            arr[i][0] = arr[i-1][0]+grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            arr[0][j] = arr[0][j-1]+grid[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                arr[i][j] = min(arr[i-1][j],arr[i][j-1])+grid[i][j];
            }
        }
        return arr[m-1][n-1];
    }
};
int main(int argc, char const *argv[]) {

    return 0;
}
