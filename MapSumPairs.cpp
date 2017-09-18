#include "inc.h"
#include <cstring>
//677. Map Sum Pairs
// class MapSum {
// public:
//     struct node{
//         struct node *next[26] = {NULL};
//         int sum;
//         node():sum(0){}
//     };
//     /** Initialize your data structure here. */
//     MapSum() {
//         root = new node();
//     }
    
//     void insert(string key, int val) {
//         node* t1 = root;
//         for (int i = 0; i < key.size(); i++) {
//             if (t1->next[key[i]-'a'] == NULL) {
//                 t1
//             }
//         }
//     }
    
//     int sum(string prefix) {
        
//     }
// private:
//     node* root;
// };

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

 class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for (auto p:m) {
            if (isPre(p.first, prefix)) {
                result+=p.second;
            }
        }
        return result;
    }
    bool isPre(string p, string prefix) {
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != p[i]) return false;
        }
        return true;
    }
private:
    unordered_map<string, int> m;
};
int main () {
    MapSum obj;
    obj.insert("ssb", 2);
    obj.insert("ssccd", 4);
    cout << obj.sum("ss") << endl;
}
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */