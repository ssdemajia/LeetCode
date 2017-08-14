#include "inc.h"
//660. Remove 9
//思路相当于将n转化为九进制下的数
class Solution {
public:
    int newInteger(int n) {
        int result = 0;
        int mod;
        int base = 1;
        while(n > 0) {

            mod = n%9;
            result = result + base*mod;
            n/=9;
            base*=10;
        } 
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.newInteger(20) << endl;
    return 0;
}
