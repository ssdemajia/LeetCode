#include "inc.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0||(x!=0&&x%10 == 0)) return false;//当x为0时是回文数，x为10^n次方时不是回文数
        int temp = x;
        int r=0;
        while(temp>r)
        {
            r*=10;
            r+=temp%10;
            temp/=10;
        }

        if (temp == r || temp == r/10)//如果是1111的形式则满足第一个条件，12321满足第二个条件
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    //0 1 10 121 12321
    if (so.isPalindrome(10)) {
        cout << "YES!"<<endl;
    }
    return 0;
}
