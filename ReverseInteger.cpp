#include <iostream>
#include <climits>
//7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x)
        {
            result *= 10;
            if (result % 10 != 0){//如果溢出了那么加过的数字会发生改变
                return 0;
            }
            result += x % 10;
            if ((result % 10) != (x %10))//如果溢出了那么加过的数字会发生改变
            {
                return 0;
            }
            x/=10;
        }
        return result;
    }
};
using namespace std;
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.reverse(900000) << endl;
    cout << so.reverse(1534236469) << endl;
    cout << so.reverse(2147483645) << endl;
    return 0;
}
