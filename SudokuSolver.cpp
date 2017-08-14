#include "inc.h"
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int> >row(9, vector<int>(9,0));//数i是否出现在行j中
        vector<vector<int> >col(9, vector<int>(9,0));//数i是否出现在列j中
        vector<vector<int> >box(9, vector<int>(9,0));//用于储存数i是否在宫j中
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.'){
                    int temp = board[i][j]-'0'-1;//temp需要减1,因为行列的范围是0～8
                    int b = i / 3 * 3 + j / 3;//i/3得到这是在以三行为一大行中的第几大行，加上列数则为宫数
                    row[temp][i]=col[temp][j]=box[temp][b]=1;
                }
            }
        }
        helper(board, row, col, box, 0, 0);
    }
    bool helper(vector<vector<char>>& board, vector<vector<int> > &row,
        vector<vector<int> >&col, vector<vector<int> >&box, int r,int c){
            if (r == 9) return true;//到达最终结果，返回
            if (c == 9) return helper(board, row, col, box, r+1, 0);//一行满了，那么将其换行
            if (board[r][c] != '.') return helper(board, row, col, box, r, c+1);
            for (int k = 0; k < 9; k++){
                int b = r / 3 * 3 + c / 3;
                if (!row[k][r] && !col[k][c] && !box[k][b]){
                    row[k][r]=col[k][c]=box[k][b]=1;//如果访问了，那么就把这个数的标记打上
                    board[r][c] = '0'+1+k;
                    if (helper(board, row, col, box, r, c+1)) return true;
                    row[k][r]=col[k][c]=box[k][b]=0;//如果这个k不对，那么把这个数标记清空
                    board[r][c] = '.';
                }
            }
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    vector<vector<char> > board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
//".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    vector<vector<char> > board = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };
    displayVec2d(board);
    cout << endl;
    so.solveSudoku(board);
    displayVec2d(board);
    return 0;
}
