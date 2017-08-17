#include "inc.h"
//357	Count Numbers with Unique Digits   
class Solution {
public:
    int permutation(int n, int r) {
        if (r <= 0) return 1;
        int result = 1;
        for (int i = 0; i < r; i++){
            result*=(n-i);
        }
        return result;
    }
    int countNumbersWithUniqueDigits(int n) {//10表示0，1,2,3,4,5,6,7,8,9
        //A(n) = P(10,n) - p(10,n-1);  p(10,n-1)表示开头为0,开头为0则不够n位数
        int result = 1;
        if (n == 0) return result;
        for (int i = n; i > 0; i--) {
            //cout << "permuttaion:"<<permutation(9,n-1)<<endl;
            result+=9*permutation(9,i-1);
        }
        return result;
    }
};
int main(){
    Solution so;
    cout << so.countNumbersWithUniqueDigits(2)<<endl;
}