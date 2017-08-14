#include "inc.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> v(s.size()+1,0);//表示i为上一个单词结尾的位置
        v[0] = 1;
        for(int i = 1; i <= s.size(); i++)//以i为结尾
        {
            for(int j = i-1; j >= 0; j--)//以j为开头的子字符串
            {
                if (v[j])//如果j是上一个单词的结尾
                {
                    string sub = s.substr(j, i-j);//那么判断这个新的字符串
                    if (find(wordDict.begin(), wordDict.end(), sub)!=wordDict.end())
                    {
                        v[i] = 1;//如果有那么就是一个结尾
                        break;
                    }
                }

            }
        }
        return v[s.size()];
    }
};
int main(int argc, char const *argv[]) {
    vector<string> wordDict = {"et","code","le"};
    string s = "leetcode";
    Solution so;
    if (so.wordBreak(s, wordDict))
    {
        cout << "YES" << endl;
    }else{
        std::cout << "NO!" << '\n';
    }
    return 0;
}
