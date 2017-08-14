#include "inc.h"
//Leetcode 60 Permutation Sequence
class Solution {
public:
    string getPermutation(int n, int k) {
        string temp;
        vector<int> prepare;
        for (int i = 1; i <=n; i++) prepare.push_back(i);
        helper(prepare, temp, n, k);
        
        return temp;
    }
    void helper(vector<int> &prepare, string &temp, int n, int k) {
        if (n > 0) {
            int segment = Cal(n-1);
            int index = (k-1)/segment;
            temp+=to_string(prepare[index]);
            //cout << "temp:"<<temp<<endl;
            prepare.erase(prepare.begin()+index);
            k = k - index*segment;
            helper(prepare, temp, n-1, k);
        }
    } 
    int Cal(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};
int main() {
    Solution so;
    cout << so.getPermutation(3,5) << endl;
    return 0;
}