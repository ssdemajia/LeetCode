#include "inc.h"
class Solution
{
public:
    vector<int> createPrefix(string p)
    {
        int length = p.size();
        vector<int> pi(length, 0);
        pi[0] = -1;//第一个元素的前缀没有，则为-1
        int k = -1;
        for(int i = 1; i < length; i++)
        {
            while (k>=0 && p[k+1] != p[i]) k = pi[k];//如果不匹配那么退回到上一个最长前缀处
            if (p[k+1] == p[i]) k = k+1;//如果匹配那么增加共同的最长前缀数
            pi[i] = k;
        }
        return pi;
    }
    int strStr(string haystack, string needle)
    {
        if (needle.size() <= 0) return 0;
        vector<int> pi = createPrefix(needle);
        displayVec(pi);
        int q = -1;//q是模板的索引
        for (int i = 0; i < haystack.size(); i++)
        {
            cout << "strStr i:"<<i<<endl;
            while (q >= 0 && needle[q+1] != haystack[i]) q = pi[q];
            if (haystack[i] == needle[q+1]) q+=1;
            //pi[i] = q;
            if (q == needle.size()-1) return i-q;//如果匹配了needle.size()个元素，则匹配成功，返回下标
        }
        return -1;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    cout << so.strStr("acbabc", "cb")<<endl;
    return 0;
}
