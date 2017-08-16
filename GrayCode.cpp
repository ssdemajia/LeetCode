#include "inc.h"
//89. Gray Code
//information from http://www.baike.com/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
class Solution {
public:
    //方法一！
    vector<int> grayCode2(int n) {//使用异或操作转化
        int len = 1<<n;
        vector<int> result;
        int base = 1;
        for (int i = 0; i < len; i++) {
           result.push_back(cal(i));
        }
        return result;
    }
    int cal(int i) {//十进制的数转化为使用Gray Code编码后
        int result = 0;
        int n = 0;
        while (i>0) {
            int one = i&1;//当前位数是0还是1
            i>>=1;//到下一个位数
            int two = i&1;//下一位数是0还是1
            int temp = one^two;//这两个位的数做异或操作
            temp <<= n;//将temp转化为n这一位的值
            n++;//到下一位数
            result+=temp;
        }
        return result;
    }
    //方法二！
    vector<int> grayCode(int n) {//使用gray code 的反射性质
        vector<int> result;
        int base = 1;
        result.push_back(0);
        result.push_back(1);
        int len = 1<<n;
        while (result.size() != len) {
            base<<=1;
            for (int i = result.size()-1; i >= 0; i--) {
                result.push_back(result[i]+base);//每次将上一个基逆序加上这次的基
            }
        }
        return result;
    }
};
int main(){
    Solution so;
    displayVec(so.grayCode(2));
    return 0;
}