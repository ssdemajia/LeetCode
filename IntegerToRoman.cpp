#include "inc.h"
//leetcode 12. Integer to Roman
class Solution {
public:
    //I表示1， V表示5，X表示10，L表示50，C表示100，D表示500，M表示1000
    string intToRoman(int num) {
        string word[4][10] {
            {"", "I", "II","III","IV","V","VI","VII","VIII","IX"},//0~9
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},//10,20,...,90
            {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},//100,200,...,900
            {"","M","MM","MMM","","","","","",""}//1000,2000,3000
        };//题目中数字范围是0~3999
        string result;
        result.append(word[3][num/1000]);//添加千位数字
        result.append(word[2][num/100%10]);//添加百位数字
        result.append(word[1][num/10%10]);//添加十位数字
        result.append(word[0][num%10]);//添加个位数字
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.intToRoman(3999)<<endl;;
    return 0;
}
