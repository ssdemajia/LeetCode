#include "inc.h"
//Leetcode 43
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string result(len1+len2, '0');
        //cout << "result:"<<result<<endl;
        //bool hasCarry = false;
        int degree = 1;
        int plus_carry = 0;//用于加法进位
        int j,i;
        for (i = len1-1; i >= 0; i--){

            int mult_carry = 0;//乘法的进位
            int a = num1[i] - '0';//乘数的当前数
            j=len2-1;
            for (; j >= 0; j--) {
                //cout << "i:"<<i<<", j:"<<j<<endl;
                int b = num2[j] - '0';//被乘数的当前位
                //cout << "b:"<<b<<endl;
                int temp = a*b+mult_carry;//当前两位数的乘积
                //cout << "reuslt[i+j]:"<<result[i+j+1]-'0'<<", temp:"<<temp<<endl;
                int c = temp%10 + result[i+j+1]-'0'+plus_carry;//当前的乘积加上上次的数
                mult_carry = temp/10;
                //cout << "plus:"<<plus_carry<<endl;
                //cout << "mult:"<<mult_carry<<endl;
                plus_carry = c/10;
                //cout << "c:"<<c<<endl;
                result[i+j+1] = '0'+c%10;

            }
            //cout << "plus:"<<plus_carry<<endl;
            if (mult_carry > 0 || plus_carry > 0){
                //cout << " i+j+1:"<<i+j+1<<endl;
                result[i+j+1] = mult_carry+'0' + plus_carry;
                mult_carry=plus_carry= 0;
            }
            //cout << "i:"<<i<<", j:"<<j<<endl;
            //cout <<"--------------------------------------"<<endl;
        }
        for (int k = 0; k < result.size(); k++) {//去除前面的0
            if (result[k] != '0'){
                result = string(result,k);
                break;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.multiply("19","1") << endl;
    return 0;
}
