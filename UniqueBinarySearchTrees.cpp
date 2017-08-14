#include "inc.h"
//leetcode 96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        if(n < 1) return 0;
        std::vector<int> v(n+1,0);
        v[0] = 1;
        v[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                v[i] += v[j]*v[i-j];
            }
        }
        displayVec(v);
        return v[n];
    }

};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.numTrees(2) << endl;
    return 0;
}
