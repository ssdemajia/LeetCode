#include "inc.h"
//201. Bitwise AND of Numbers Range
class Solution {
public:
/* 
思路：通过找到规律，先从个位开始，只要m和n相差长度大于1，则个位必为0，十位是相差长度大于1>>1即2，则个数大于2
当m的二进制长度小于n时，那么n长的那些位数直接是0
 */
    int rangeBitwiseAnd(int m, int n) {
        int result = m&n;
        //cout << "result:" << result << endl;
        int length = len(m);
        //cout << length << endl;
        unsigned int  circle = 1;
        for (int i = 0; i < length; i++) {
            if (n-m > circle) {
                result &= (~circle);//将这一位化为0
                circle<<=1;
            }else {
                return result;
            }
        }
        return result;
    }
    int len(int n) {
        int result = 0;
        while (n) {
            result++;
            n>>=1;
        }
        return result;
    }
};
int main ()
{
    Solution so;
    cout << so.rangeBitwiseAnd(5,7) << endl;
    return 0;
}