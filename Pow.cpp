#include "inc.h"
#include <limits>
//Leetcode 50
class Solution {
public:
    double myPow2(double x, int n) {//自己写的，x一共乘以n次，比较慢
        cout << "x:"<<x<<" , n:"<<n<<endl;
        bool isMinus = false;
        bool isX = false;
        long m = n;
        double result = 1;
        if (m < 0) {
            isMinus = true;
            m = abs(m);
        }
        if (x < 0) {
            isX = true;
            x = -x;
        }
        long N = m;
        cout << "N:"<<N<<endl;
        while (N > 0) {
            double temp = result;//保存上一次的结果
            result *= x;
            if (result < 0.000001) break;
            if (abs(result - temp) == 0) break;
            if (result > numeric_limits<double>::max()) return 0;
            cout << result << endl;
            if (result < 0) return -1;
            --N;
        }
        cout << "result:"<<result<<endl;
        result =  isMinus?1.0/result:result;
        if (isX){
            result = n%2==0?result:-result;
        }
        return result;
    }
    double myPow(double x, int n) { //对于指数，化为二进制，只需要logn的次数
        if(x==1 || n==0) return 1;//特殊情况
        if(x==-1 && n%2 == 0) return 1;
        if (x==-1 && n%2 == 1) return -1;
        long m = n;//指数，用long来防止出现n是-2147483648的情况，这种情况下-n依然是-2147483648
        if (m < 0) {
            m = -m;
            x = 1.0/x;//因为指数为负，那么将其转换位正数，x变为分数
        }
        double result = 1.0;
        while(m){//一开始x^1,然后x^2, x^4, x^8，... ，x^m可以由1,2,4,8...m组成指数n
            if (m&1)result *= x;
            //如果这一位是为1,意味着能够拆分成包括一位的2^n的相乘的结果
            x*=x;//x变成x^2n
            m>>=1;
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
// double x = 34.00515; int n = -3;
//double x = 0.00001; int n = 2147483647;
double x = 0.99999; int n = 948688;
//double x = 1.00000; int n = 2147483647;
//double x = 2.00000; int n = -2147483648;
    cout << so.myPow(x,n) << endl;
    return 0;
}
