#include "inc.h"
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
  int val = NULL;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int> > result;
    if (!root) {
      return result;
    }
    queue<Node *> q;
    
    int index = 0;
    int edge = 0;
    vector<int> *row = new vector<int>();
    q.push(root);
    while (!q.empty()) {
      Node* q_front = q.front();
      q.pop();
      for (auto i : q_front->children) {   // 层级遍历
        q.push(i);
      }
      row->push_back(q_front->val);
      if (index == edge) {  // 遍历到边界，需要把边界前的值保存
        result.push_back(*row);
        edge = q.size()-1;
        index = 0;
        row = new vector<int>();
      }
      else {
        index++;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution so;
  Node* p3 = new Node(3, vector<Node*>({new Node(6, vector<Node*>()), new Node(7, vector<Node*>())}));
  Node* p4 = new Node(4, vector<Node*>({new Node(8, vector<Node*>()), new Node(9, vector<Node*>())}));
  Node* p5 = new Node(5, vector<Node*>({new Node(10, vector<Node*>()), new Node(11, vector<Node*>())}));
  Node* root = new Node(1, vector<Node*>({p3, p4, p5}));
  vector<vector<int> > result = so.levelOrder(root);
  displayVec2d(result);
  return 0;
}
