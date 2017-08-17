#include "inc.h"
#include <memory>
//208. Implement Trie
class Trie {
    struct Node{
        vector<Node*> alpha;
        bool isWord;
        Node():alpha(26,NULL),isWord(false){}
      };
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();//计算字符串长度
        Node * p = root;//从根结点向下遍历
        for (int i = 0; i < len; i++) {
            int id = word[i] - 'a';
            if (p->alpha[id] == NULL) {
                p->alpha[id] = new Node();                
            }
            
            p = p->alpha[id];
        }
        p->isWord = true;//表明这个结尾是一个单词
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();//计算字符串长度
        Node * p = root;//从根结点向下遍历
        for (int i = 0; i < len; i++) {
            int id = word[i] - 'a';
            Node* next = p->alpha[id];
            if (next){
                p = next;
            }
            else{//如果word遍历还没结束，trie的向下遍历已经结束了
                return false;
            }
        }
        if (p && p->isWord) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();//计算字符串长度
        Node * p = root;//从根结点向下遍历
        for (int i = 0; i < len; i++) {
            int id = prefix[i] - 'a';
            Node* next = p->alpha[id];
            if (next){
                p = next;
            }else{//如果前缀遍历还没结束，trie的向下遍历已经结束了
                return false;
            }
        }
        return true;
    }
    Node *root;
};
int main() {
    Trie t;
    t.insert("absd");
    t.insert("bcr");
    if (t.search("bcrc")) cout << "Yes!"<<endl;
    else cout << "No!!"<<endl;
}