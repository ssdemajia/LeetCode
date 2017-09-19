#include "inc.h"
//676. Implement Magic Dictionary
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string s:dict) {
            dicts.insert(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (string i : dicts) {
            if (i.size() == word.size() && check(i, word)) return true;
        }
        return false;
    }
    bool check(string temp, string word) {
        bool hasWrong = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != temp[i]) {
                if (!hasWrong) hasWrong = true;
                else return false;
            }
        }
        if (hasWrong) return true;
        return false;
    }
private:
    
    set<string> dicts;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
 int main() {
     MagicDictionary obj;
     vector<string> dict = {"hello", "leetcode"};
     obj.buildDict(dict);
     string word = "leetcodd";
     if (obj.search(word)) {
         cout << "Yes!" << endl;
     }
     else {
         cout << "No!" << endl;
     }
 }