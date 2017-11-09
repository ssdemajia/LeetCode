#include "inc.h"
//165. Compare Version Numbers
class Solution {
public:
    /* 
    思路：主要是考虑遇到'.'时或者其中一个到达尽头时，当小于长度或者不是‘.’时就直接做变成数
    */
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int p1 = 0, p2 = 0;
        int num1 = 0, num2 = 0;
        while (p1 < len1 || p2 < len2) {
            if (p1 < len1 ) {
                if (version1[p1] != '.') {
                    num1 = num1*10 + version1[p1]-'0';
                    p1++;
                }
            }
            if (p2 < len2) {
                if (version2[p2] != '.') {
                    num2 = num2*10 + version2[p2]-'0';
                    p2++;
                }
            }
            if ((version1[p1] == '.' || p1 == len1)&&(version2[p2] == '.' || p2 == len2)){
                if (num1 > num2) {
                    return 1;
                }else if (num1 < num2) {
                    return -1;
                }else {
                    if (p1 < len1) p1++;
                    if (p2 < len2) p2++;
                    num1 = num2 = 0;
                }  
            }
        }
        if (num1 > num2) {
            return 1;
        }else if (num1 == num2) {
            return 0;
        }else {
            return -1;
        }  
        return 0;
    }
};
int main() {
    Solution so;
    vector<string> version1 = {
        "0.01.1",
        "1.01.1"
    };
    if (so.compareVersion(version1[0], version1[1]) == 1) {
        cout << "Great"<<endl;
    }
    else if (so.compareVersion(version1[0], version1[1]) == -1) {
        cout << "Less" << endl;
    }else {
        cout << "Equal" << endl;
    }
    return 0;
}