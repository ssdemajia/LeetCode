#include "inc.h"
//187. Repeated DNA Sequences
class Solution {
public:
/* 
思路1：直接找到子字符串将其放入map其中
 */
    vector<string> findRepeatedDnaSequences1(string s) { 
        unordered_map<string, int> m;
        vector<string> result;
        if (s.size()==0 || s.size() < 10) return result;
        for (size_t i = 0; i <= s.size()-10; i++) {
            string temp = s.substr(i, 10);
            if (m[temp]== 1) {
                result.push_back(temp);
            }
            m[temp]++;
        }
        return result;
    }
    /* 
    思路2：ATGC这四个字符的为数字不同，那么直接保存其为3位
    A is 0x41, C is 0x43, G is 0x47, T is 0x54 十六进制时
    A is 0101, C is 0103, G is 0107, T is 0124 八进制时
     */
    vector<string> findRepeatedDnaSequences(string s) { 
        unordered_map<int, int> m;
        vector<string> result;
        if (s.size()==0 || s.size() < 10) return result;

        int temp = 0;
        for (int i = 0; i < 10; i++) {
            temp = (temp << 3) | (s[i]&0x7);
        }
        m[temp]++;
        for (size_t i = 10; i < s.size(); i++) {
            temp = ((temp << 3) | (s[i]&0x7)) & 0x3fffffff;//控制为30bit
            m[temp]++;
            if (m[temp] == 2) result.push_back(s.substr(i-9, 10));
        }
        return result;
    }
};
int main()
{
    string s = "AAAAATCCCCCAAAAATCCCCCCAAAAAGGGTTT";
    // string s = "A";
    string s1 = "AAAAAAAAAAA";
    Solution so;
    displayVec(so.findRepeatedDnaSequences(s));
    return 0;
}