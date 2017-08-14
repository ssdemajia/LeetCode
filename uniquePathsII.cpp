#include "inc.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        cout << "m:"<<m<<", n:"<<n<<endl;
        int arr[m][n];
        if (obstacleGrid[0][0] == 1)
        {
            arr[0][0] = 0;
        }
        else
        {
            arr[0][0] = 1;
        }
        for(int i =1; i < m; i++)
        {
            if(obstacleGrid[i][0]==1){
                arr[i][0] = 0;
            }
            else arr[i][0] = arr[i-1][0];
        }
        for(int i = 1; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1) {
                arr[0][i] = 0;
            }
            else
                arr[0][i] = arr[0][i-1];
        }
        int a;
        int b;
        for(int i = 1; i <m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if (obstacleGrid[i-1][j] == 1)
                {
                    a = 0;
                }
                else
                {
                    a = arr[i-1][j];
                }
                if (obstacleGrid[i][j-1] == 1)
                {
                    b = 0;
                }
                else
                {
                    b = arr[i][j-1];
                }
                cout << "a:"<<a<<",b:"<<b<<endl;
                arr[i][j] = a+b;
            }
        }
        return arr[m-1][n-1];
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<int> > v = {{0,0,0},
                                {0,1,0},
                            {0,0,1}};
    Solution so;
    cout << so.uniquePathsWithObstacles(v) << endl;
    return 0;
}
