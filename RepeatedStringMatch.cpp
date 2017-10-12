#include "inc.h"
//686. Repeated String Match
class Solution {
public:
    /* 
    思路：a要重复几次能够使b是其子字符串，即重复k次使 A = k * a， b == A.substring
    首先计算k的大小，b要是A的子字符串，至少需要A的长度大于等于b，这个len(b)/len(a)要向上取整，
    所以需要k = (len(b)-1)/len(a)+1,通过对其使用查找函数，如果找不到，再加一次a到A上，即k+1，
    如果还是不行，则表示b不是A的子字符串。
    */
    int repeatedStringMatch(string A, string B) {
        string temp = A;        
        int q = (B.size()-1)/A.size()+1;//
        for (int i = 1; i < q; i++) A += temp;
        for (int k = 0; k < 2; k++) {            
            if (A.find(B)!=A.npos)  return A.size()/temp.size();
            A += temp;
        }
        return -1;
    }
};
int main() {
    string a1 = "abab";//1
    string b1 = "a";

    string a2 = "abcabcabcabc";//
    string b2 = "abac";

    string a = "abababaaba";//2
    string b = "aabaaba";

    string a3 = "abcdefg";
    string b3 = "efga";

    string a4 = "abcd";
    string b4 = "cdabcda";

    string a5 = "aa";
    string b5 = "a";

    string a6 = "a";
    string b6 = "aa";
    Solution so;
    cout << so.repeatedStringMatch(a, b) << endl;
    return 0;
}