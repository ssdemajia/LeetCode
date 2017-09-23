#include "inc.h"
//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[index]) index++;
        }
        return index == s.size();
    }
};
int main() {
    string s = "abx";
    string t = "aahbgdc";
    Solution so;
    if (so.isSubsequence(s, t)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}