#include "inc.h"
//130. Surrounded Regions


/* 
思路：主要是区域四周的‘o’，一直延伸到被标记为‘1’，则内部的‘o’保持不变，直到最后两个循环将其‘1’变成‘o’，内部的‘o’变成‘x’
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        for (int i = 0; i < board.size(); i++) {
            hasSurround(board, i, 0);
            hasSurround(board, i, board[i].size()-1);
        }
        for (int i = 0; i < board[0].size(); i++) {
            hasSurround(board, 0, i);
            hasSurround(board, board.size()-1, i);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '1') {                    
                    board[i][j] = 'O';
                }
            }
        }
    }
    void hasSurround(vector<vector<char>>& board,int i, int j) {      
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i>0) hasSurround(board,i-1,j);
            if (i<board.size()-1) hasSurround(board,i+1,j);
            if (j > 0) hasSurround(board, i, j-1);
            if (j < board[i].size()-1) hasSurround(board, i, j+1);
        }
        
    }
};
int main(){
    vector<vector<char>> board = {
        {'X','X','X','X','O'},
        {'X','O','O','X','X'},
        {'X','O','O','O','X'},
        {'X','O','X','X','X'},
        {'X','O','X','X','X'}
    };
    
    Solution so;
    so.solve(board);
    displayVec2d(board);
    return 0;
}