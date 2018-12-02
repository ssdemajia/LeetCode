#include "inc.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        max_depth = 0;
        int depth = 0;
        helper(root, 0);
        return max_depth;
    }
    void helper(Node* root, int depth) {
      cout << depth << ", " <<  root->val << endl;
        vector<Node*> children = root->children;
        if (children.size()==0) {
            max_depth = max(depth + 1, max_depth);
            return;
        }
        for (auto c : children) {
            helper(c, depth + 1);
        }
    }
private:
    int max_depth;
};

int main(int argc, char const *argv[])
{
  Solution so;
  Node* p3 = new Node(3, vector<Node*>({new Node(6, vector<Node*>()), new Node(7, vector<Node*>())}));
  Node* p4 = new Node(4, vector<Node*>({new Node(8, vector<Node*>()), new Node(9, vector<Node*>())}));
  Node* p5 = new Node(5, vector<Node*>({new Node(10, vector<Node*>()), new Node(11, vector<Node*>())}));
  Node* root = new Node(1, vector<Node*>({p3, p4, p5}));
  int result = so.maxDepth(root);
  cout << result << endl;
  return 0;
}