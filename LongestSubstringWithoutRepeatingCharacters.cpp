#include "inc.h"
class Solution {
public:
    int lengthOfLongestSubstring3(string s) {//使用暴力解法，考虑了每一个substring(i,j)
        //std::cout << "/* message */"<<s.size()2 << '\n';
        int result = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = i+1; j < s.size(); j++) {
                if (!check(s, i, j)) {
                    //cout << s.substr(i, j-i)<<endl;
                    break;
                }
                if (j-i > result) result = j-i;
            }

        }
        return result;
    }
    bool check(string s, int start, int end) {
        unordered_set<char> set;
        for (int i = start; i < end; i++) {
            char temp = s[i];
            if (set.count(temp) > 0) return false;
            else set.insert(temp);
        }
        return true;
    }
    int lengthOfLongestSubstring2(string s) {//使用一个set保存一个窗口，这个窗口里没有重复的字符
        //std::cout << "/* message */"<<s.size()2 << '\n';
        int result = 0;
        int len = s.size();
        int low = 0;
        int high = 0;
        unordered_set<char> set;
        while (low < len && high < len) {
            if (set.count(s[high]) == 0) {
                set.insert(s[high++]);
                result = max(result, high-low);
            }
            else {
                set.erase(s[low++]);
            }
        }
        return result;
    }
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int len = s.size();
        vector<int> map(127,0);
        int i = 0;//i是子字符串的第一个
        for (int j = 0; j < len; j++) {//j是子字符串最后一个
            if (map[static_cast<int>(s[j])] != 0 ) {
                i = max(map[s[j]], i);//如果遇到s[j]是前面重复的字符，如果不加max那么i会回退到很前面
            }//实际前面重复的字符已经检测过了
            result = max(result, j-i+1);
            map[static_cast<int>(s[j])] = j+1;//每次把遇到重复字符i回退的位置放入map[s[j]]代表的数组中
        }

        return result;
    }
};
int main(int argc, char const *argv[]) {
    unordered_map<string, int> v = {
        {"abcabcbb",3},
        {"bbbbb",1},
        {"pwwkew",3}

    };
    Solution so;
    for (auto p = v.cbegin(); p != v.cend(); p++){
        int result = so.lengthOfLongestSubstring(p->first);
        if (result != p->second){
            std::cout << "Oops! "<<p->first<<" is wrong!" <<result<< '\n';
        }else{
            std::cout << "Yeah! "<<p->first<<" is right!" << '\n';
        }
    }
    return 0;
}
