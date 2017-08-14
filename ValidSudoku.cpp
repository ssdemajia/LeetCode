#include "inc.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int> >row(9, vector<int>(9,0));//数i是否出现在行j中
        vector<vector<int> >col(9, vector<int>(9,0));//数i是否出现在列j中
        vector<vector<int> >box(9, vector<int>(9,0));//用于储存数i是否在宫j中
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.'){
                    int temp = board[i][j]-'0'-1;//temp需要减1,因为行列的范围是0～8
                    int b = i / 3 * 3 + j / 3;//i/3得到这是在以三行为一大行中的第几大行，加上列数则为宫数
                    if (row[temp][i] || col[temp][j]||box[temp][b]){
                        return false;
                    }
                    row[temp][i]=col[temp][j]=box[temp][b]=1;
                }
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    vector<vector<char> > board = {
        {'5','3','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };
    if (so.isValidSudoku(board)) std::cout << "/* message */" << '\n';
    else std::cerr << "Fuck you!" << '\n';
    return 0;
}
