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

class Solution {
public:
    vector<int> preorder(Node* root) {    // 非递归
      if (!root) return result;
      stack<Node*> s;
      Node* current_node = root;
      s.push(root);
      while (!s.empty()) {
        current_node = s.top();
        cout << current_node->val << endl;
        s.pop();
        result.push_back(current_node->val);
        for (int i = current_node->children.size() - 1; i >=0; i--) {
          s.push(current_node->children[i]);
        }
        
      } 
      return result;       
    }

    vector<int> preorder2(Node* root) {    // 递归
      inner(root);
      return result;     
    }
    void inner(Node* root) {
      if (!root) {
        return;
      }
      result.push_back(root->val);
      for(auto children : root->children) {                  
        inner(children);
      }
    }
private:
  vector<int> result;
  unordered_map<Node*, int> node_to_children_index;
};

int main(int argc, char const *argv[])
{
  Solution so;
  Node* p3 = new Node(3, vector<Node*>({new Node(6, vector<Node*>()), new Node(7, vector<Node*>())}));
  Node* p4 = new Node(4, vector<Node*>({new Node(8, vector<Node*>()), new Node(9, vector<Node*>())}));
  Node* p5 = new Node(5, vector<Node*>({new Node(10, vector<Node*>()), new Node(11, vector<Node*>())}));
  Node* root = new Node(1, vector<Node*>({p3, p4, p5}));
  vector<int> result = so.preorder(root);
  displayVec(result);
  return 0;
}
