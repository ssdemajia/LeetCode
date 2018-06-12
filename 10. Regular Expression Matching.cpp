#include "inc.h"
struct Edge;
struct Node {
    bool isEnd;
    vector<Edge*> in;
    vector<Edge*> out;
    Node(bool isEnd=false) {
        this->isEnd = isEnd;
    }
};
struct Edge {
    char c;
    Node* from;
    Node* to;
};
class Solution {
public:
    bool isMatch1(string s, string p) {
        Node * start = createRegular(p);
        return false;
    }
    Node * createRegular(string p) {
        Node* start = new Node();
        Node* current = start;
        for (int i = 0; i < p.size(); i++) {
            switch(p[i]){
                case '.':
                    
                    break;
                case '*':

                    break;
                default:
                    Edge* edge = new Edge();
                    edge->c = p[i];
                    current->out.push_back(edge); //这条状态边放入当前节点的out边
                    Node* next = new Node();
                    next->in.push_back(edge);   //这条边放入当前节点的in边
                    edge->from = current;
                    edge->to = next;
                    current = next;
            }
        }
        return start;
    }
    bool isMatch(string s, string p) {
        return matchNow(s, 0, p, 0);
    }
    bool matchNow(string &s, int is, string &p, int ip) {
        if (is == s.size() && ip == p.size()) {
            return true;
        } else if (p[ip+1] == '*') {
            return matchStar(p[ip], s, is, p, ip+2);
        } else if (is < s.size() && (s[is] == p[ip] || p[ip] == '.')) {
            return matchNow(s, is+1, p, ip+1);
        }
        return false;
    }
    bool matchStar(char c, string &s, int is, string &p, int ip) {
        if (matchNow(s, is, p, ip)) return true;
        while (is < s.size() && (c == s[is] || c == '.')) {
            is++;
            if (matchNow(s, is, p, ip)) return true;
        }
        return false;
    }
};

// 测试用例
int main(int argc, char const *argv[])
{
    Solution so;
    SS_ASSERT(so.isMatch("aaa", "aaaa") == false);
    SS_ASSERT(so.isMatch("aabcba", "a*b.*a") == true);
    SS_ASSERT(so.isMatch("aaa", "ab*a*c*a") == true);
    SS_ASSERT(so.isMatch("aaabab", "a*bab") == true);
    SS_ASSERT(so.isMatch("aaa", "a*a") == true);
    SS_ASSERT(so.isMatch("ab", ".*c") == false);
    SS_ASSERT(so.isMatch("a",".")==true);
    SS_ASSERT(so.isMatch("a","*")==false);
    SS_ASSERT(so.isMatch("ab",".*c") == false);
    SS_ASSERT(so.isMatch("ab", ".*") == true);
    SS_ASSERT(so.isMatch("aab", "c*a*b")==true);
    SS_ASSERT(so.isMatch("aa", ".a")==true);
    SS_ASSERT(so.isMatch("sddg", "s.*g")==true);
    SS_ASSERT(so.isMatch("mississippi", "mis*is*p*.")==false);
    return 0;
}
