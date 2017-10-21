#include "inc.h"
//127. Word Ladder
class Solution {
public:
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {//使用单个set
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> next_words;
        next_words.insert(beginWord);
        int len = beginWord.size();
        int length = 1;
        while(!next_words.empty()) {
            unordered_set<string> temp;
            length++;
            for (string s: next_words) {
                //cout << s << endl;
                for (int i = 0; i < len; i++) {
                    char letter = s[i];
                    for (int j = 0; j < 26; j++) {
                        s[i] = 'a'+j;
                        
                        if (words.count(s) ==1) {
                            if (s == endWord) return length;
                            temp.insert(s);
                            words.erase(s);
                        }

                    }
                    s[i] = letter;
                }
            }
            swap(next_words, temp);
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {//使用两个set
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        unordered_set<string> next_words;
        unordered_set<string> prev_words;
        next_words.insert(beginWord);
        prev_words.insert(endWord);
        words.erase(beginWord);
        words.erase(endWord);
        int len = beginWord.size();
        int length = 2;
        while(!next_words.empty() && !prev_words.empty()) {
            unordered_set<string> temp;
           if (prev_words.size() < next_words.size()) {
                swap(prev_words, next_words);
            }
            for (string s: next_words) {
                for (int i = 0; i < len; i++) {
                    char letter = s[i];
                    for (int j = 0; j < 26; j++) {
                        s[i] = 'a'+j;
                        if (prev_words.count(s)==1) return length; 
                        if (words.count(s) ==1) {
                            temp.insert(s);
                            words.erase(s);
                        }

                    }
                    s[i] = letter;
                }
                for (string j : prev_words){
                    cout << j <<" ";
                }
                cout << endl;
            }
            length++;
            swap(next_words, temp);
        }
        return 0;
    }
    
};
int main() {
    Solution so;
    vector<string> words = {"hot","dot","dag","lot","esg","cog"};//"hit","cog"
    vector<string> words2 = {"hot","dot","dog","lot","log"};//"hit","cog"
    vector<string> words1 = {"hot","dog","dot"};//"hot","dog"
    cout << so.ladderLength("hit","cog", words)<<endl;
    // if (so.diff_once("hit", "hoo")) cout<<"Yes"<<endl;
    // else cout << "No"<<endl;
}