#include "inc.h"
//211. Add and Search Word - Data structure design
class WordDictionary {
public:  
    struct Node{
        Node* alpha[26];
        string s;
      };
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.size();//计算字符串长度
        Node * p = root;//从根结点向下遍历
        for (int i = 0; i < len; i++) {
            int id = word[i] - 'a';
            if (p->alpha[id] == NULL) {
                p->alpha[id] = new Node();                
            }
            
            p = p->alpha[id];
            //p->count+=1;
        }
        p->s = word;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {       
        return helper(root, 0, word);
    }
    bool helper(Node *p, int index, string word) {
        if (p->s == word) return true;
        if (word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                Node *temp = p->alpha[i];
                word[index] = i+'a';
                if (temp&&helper(temp, index+1, word)){
                    return true;
                }
               
            }
        }
        else if (word[index] <='z'&& word[index]>='a'){
             Node *temp = p->alpha[word[index]-'a'];
             if (temp) {
                return helper(temp, index+1, word);
             }
        }
        return false;
    }
private:
    Node * root;    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 int main(){
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    if (wd.search(".at")) cout << "Yes!"<<endl;
    else cout << "No!!"<<endl;
    wd.addWord("bat");
    if (wd.search(".ae")) cout << "Yes!"<<endl;
    else cout << "No!!"<<endl;
    return 0;
 }