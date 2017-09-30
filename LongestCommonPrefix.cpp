#include "inc.h"
//14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        int step = 0;
        while (step < strs[0].size()) {
            for (int i = 0; i < strs.size(); i++) {
                  if (strs[i][step] != strs[0][step]) return strs[0].substr(0,step);
            }
            step++;
        }
        return strs[0].substr(0,step);
    }
};
int main() {
    vector<string> strs1 = {
        "string","strdd","strsa","st"
    };
    vector<string> strs = {"abca","abc"};
    Solution so;
    cout << so.longestCommonPrefix(strs) << endl;
    return 0;
}