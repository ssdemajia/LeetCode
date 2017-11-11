#include "inc.h"
//166. Fraction to Recurring Decimal
class Solution {
public:
/* 
思路主要是模拟手算的除法，通过寻找重复的余数来检测循环小数，无理数（比如π）是不能
由分数表示，一直输出小数直到找到重复的余数来停止
 */
    string fractionToDecimal(int numerator, int denominator) {
        vector<long> nums(1000, 0);
        vector<long> reme(1000, 0);//保存余数
        long nume = (long)numerator;
        long demo = (long)denominator;
        bool isNegative = (double)nume/demo < 0 ? true : false;
        bool isInterger = nume%demo == 0 ? true : false;
        nume = abs(nume);
        demo = abs(demo);
        for (int i = 0; i < 1000; i++) {
            nums[i] = nume/demo;  
            reme[i] = nume%demo;
            nume = reme[i] * 10;
            if (reme[i] == 0) {
                break;
            }
        }
        // displayVec(reme);
        // cout << "------------------------------" << endl;
        // displayVec(nums);
        pair<int, int> loop = find(reme);
        //cout << loop.first << "," << loop.second << endl;
        string result;
        if (isNegative) result+="-";
        result+=to_string(nums[0]);
        if (!isInterger) result+=".";
        
        for (int i = 1; i <= loop.first; i++) {
            result += to_string(nums[i]);
        }
        if (nums[loop.first+1] == 0 && nums[loop.second] == 0){
            return result;
        }
        if (loop.first != loop.second) {
            result+="(";
            for (int i = loop.first+1; i <= loop.second; i++) {
                result += to_string(nums[i]);
            }
            result+=")";
        }


        return result;
    }
    pair<int, int>  find(vector<long> &reme) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < 1000; i++) {
            for (int j = i+1; j < 1000; j++) {
                if (reme[i] == reme[j]) {
                    start = i;
                    end = j;
                    return {start, end};
                }
            }
        }
        return {start, end};
    }
};
int main() {
    Solution so;
    cout << so.fractionToDecimal(-1, -2147483648) << endl;
    long long s = 7 / (long)(-12);
    cout << s << endl;
    return 0;
}