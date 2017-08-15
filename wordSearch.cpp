#include"inc.h"
//LeetCode 79 Word Search
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {//找到与word第一个字符一样的位置(i,j)
                    vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(),false));
                    if (dfs(visited, board, word, 1, i, j)) {return true;}
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<bool>>&visited, vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index == word.size()) return true;
        bool up,down,left,right;
        up = down = left = right = false;
        visited[row][col] = true;
        if (row > 0 && board[row-1][col] == word[index]&&!visited[row-1][col]){
            up =  dfs(visited, board, word, index+1, row-1, col);
        }//向上走
        if (row < board.size()-1 && board[row+1][col] == word[index]&&!visited[row+1][col]) {
            down = dfs(visited, board, word, index+1, row+1, col);
        }//向下走
        if (col > 0 && board[row][col-1] == word[index]&&!visited[row][col-1]){
            left =  dfs(visited, board, word, index+1, row, col-1);
        }
        if (col < board[row].size()-1 && board[row][col+1] == word[index]&&!visited[row][col+1]) {
            right = dfs(visited, board, word, index+1, row, col+1);
        }
        if (up||down||left||right) return true;
        visited[row][col] = false;//如果上下左右都没有，那么这个数不应该被包括，所以把visited改为false
        return false;
    } 
};
int main (){
    Solution so;
    vector<vector<char> > board1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    vector<vector<char>> board2 = {{'A','A'}};//word = "aaa"
    vector<vector<char>> board3 = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };//WORD = "ABCESEEEFS"
    if (so.exist(board3, "ABCESEEEFS")) cout << "Yes!"<<endl;
    else cout << "No!!"<<endl;
    return 0;
}