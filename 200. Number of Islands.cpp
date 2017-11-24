#include "inc.h"
//200. Number of Islands
class Solution {
public:
/* 
思路：主要是遇到‘1’就把所有连接的‘1’也全部变成‘0’
 */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() < 1) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    helper(grid, i, j);
                }
            }
        }      
        return count;
    }
    void helper(vector<vector<char>>& grid, int row, int col) {
        if (row < grid.size()-1 && grid[row+1][col] == '1')
        {
            grid[row+1][col] = '0';
            helper(grid, row+1,col);
        }
        if (row > 0 && grid[row-1][col] == '1')
        {
            grid[row-1][col] = '0';
            helper(grid, row-1,col);
        }
        if (col < grid[row].size()-1 && grid[row][col+1] == '1')
        {
            grid[row][col+1] = '0';
            helper(grid, row, col+1);
        }
        if (col > 0 && grid[row][col-1] == '1')
        {
            grid[row][col-1] = '0';
            helper(grid, row, col-1);
        }
    }
};
int main()
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution so;
    cout << so.numIslands(grid) << endl;
    return 0;
}