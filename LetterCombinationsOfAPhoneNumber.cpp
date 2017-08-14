#include "inc.h"
//leetcode 17
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone {
            "",
            "",
            "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string> strings;
        for (int i = 0; i < digits.size(); i++) {
            strings.push_back(phone[digits[i] - '0']);
        }
        vector<string> result;
        helper(result, strings, 0, "");
        return result;
    }
    void helper(vector<string> &result, vector<string> &strings, int index, string temp) {
        if (index == strings.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < strings[index].size(); i++) {
            helper(result, strings, index+1, temp+strings[index][i]);
        }
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    vector<string> strings = {
        "23",
        "45",
        "78"
    };
    for (auto str : strings){
        displayVec(so.letterCombinations(str));
    }

    return 0;
}
