#include "inc.h"
//49. Group Anagrams
class Solution {
public:
    vector<vector<string> > groupAnagrams2(vector<string>& strs) {//这个方法超时了
        vector<vector<string> > result;
        //unordered_map<string, vector<string>> m;
        vector<bool> isJoin(strs.size(), false);
        for (int i = 0; i < strs.size(); i++) {
            if (isJoin[i]) continue;
            isJoin[i] = true;
            vector<string> temp;
            temp.push_back(strs[i]);
            for (int j = 1+i; j < strs.size(); j++) {
                if (isJoin[j]) continue;
                if (check(strs[i], strs[j])) {
                    isJoin[j] = true;
                    temp.push_back(strs[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
    bool check(string &source, string &dest) {
        if (source.size()!= dest.size()) return false;
        unordered_map<char, int>m;
        for(int i = 0; i < source.size(); i++) {
            m[source[i]]++;
            m[dest[i]]--;
        }
        for (auto p : m) {
            if (p.second != 0) return false;
        }
        return true;
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> m;
        for (string i : strs) {
            string s = i;
            sort(s.begin(), s.end());//如果是一样字符组成的字符串，那么排序后也是一样的
            m[s].push_back(i);//将i其插入到，排序后字符串作为索引的map中
        }
        vector<vector<string>> result;
        for (auto p: m){
            result.push_back(p.second);
        }
        return result;
    }
};
int main(){
    vector<string> strs = {
        "ceat","teac","tan","ate","nat","bat"
    };
    vector<string> strs2 = {"","",""};
    Solution so;
    //if (so.check(strs[0], strs[2])) cout << "Yes!!" << endl;
    displayVec2d(so.groupAnagrams(strs));
    return 0;
}