#include "inc.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string> > r(n, vector<string>(n, "."));
      helper(r, 0);
      return result;
    }
    void helper(vector<vector<string> > & r, int row) {
      if (row == r.size()) {
        vector<string> temp;
        for(vector<string> v: r) {
          string rowString = "";
          for (auto i : v) {
            rowString += i;
          }
          temp.push_back(rowString);
        }
        result.push_back(temp);
        return;
      }
      for (int col = 0; col < r.size(); col++) {
        if (canPut(r, row, col)) {
          r[row][col] = "Q";
          helper(r, row+1);
          r[row][col] = ".";
        }
      }
    }
    bool canPut(vector<vector<string> > & r, int row, int col) {     
      int n = r.size();
      for (int i = 0; i < r.size(); i++) {  // 判断列和行里是否已经有Q
        if (r[i][col] == "Q" || r[row][i] == "Q") {
          return false;
        }
      }
      for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {  // 判断左上角是否有Q
        if (r[i][j] == "Q") {
          return false;
        }
      }
      for (int i = row, j = col; i >= 0 && j < n; i--, j++) {// 判断右上角是否有Q
        if (r[i][j] == "Q") {
          return false;
        }
      }
      return true;
    }
private:
  vector<vector<string>> result;
};

int main(int argc, char const *argv[])
{
  Solution so;
  vector<vector<string> > result = so.solveNQueens(3);
  return 0;
}
