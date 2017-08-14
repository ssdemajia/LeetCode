#include "inc.h"
//leetcode 413 Arithmetic Slices
class Solution {
public:
   int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        for(int i = 0; i < A.size(); i++)
        {
            int d = A[i+1]- A[i];
            for (int j = i; j < A.size()-1; j++)
            {
                if (A[j+1]- A[j] != d)
                {
                    break;
                }
                if ((j-i+2) >= 3) result++;
            }
        }
        return result;
    }
    int numberRecursion(vector<int> &A)//递归方法的主方法
    {
        int sum = 0;
        recursion(A, A.size()-1, sum);
        return sum;
    }
    int recursion(vector<int> &A, int i, int &sum)//递归的方法
    {
        if (i < 2) return 0;
        int cur = 0;
        //cout << "i:"<<i<<endl;
        if (A[i] - A[i-1] == A[i-1]-A[i-2])
        {
            cur= recursion(A, i-1, sum)+1;
            //cout << "cur:"<<cur<<endl;
            sum+=cur;
        }
        else
        {
            //cout << "2) i:" <<i<<endl;
            recursion(A,i-1, sum);
        }
        return cur;
    }
    int dp(vector<int> &A)//动态规划的方法，使用dp数组储存临时的变量
    {
        std::vector<int> dp(A.size(), 0);
        int result = 0;
        for(int i = 2;i < A.size(); i++)
        {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1]+1;
                result += dp[i];
            }
            else{
                dp[i] = 0;
            }
        }
        return result;
    }
    int dp2(vector<int> &A)//不使用额外的空间来储存临时dp值
    {
        int dp = 0;
        int result = 0;
        for(int i = 2;i < A.size(); i++)
        {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp+=1;
                result += dp;
            }
            else{
                dp = 0;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {1,2,3,4,7,8,9};
    Solution so;
    cout << so.dp2(v) << endl;
    return 0;
}
