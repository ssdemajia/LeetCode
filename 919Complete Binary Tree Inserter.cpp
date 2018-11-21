#include "inc.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
      _build(root);
    }
    
    void _build(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        nodes.push_back(temp);
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
      }
    }
    int insert(int v) {
      TreeNode* node = new TreeNode(v);
      nodes.push_back(node);
      int length = nodes.size()-1;
      TreeNode* parent = nodes[(length-1)/2];
      if (length%2 == 1) { // left node
          cout << node->val << " " << parent->val<<endl;
        parent->left = node;
      } else {
        parent->right = node;
      }
      return parent->val;
    }
    
    TreeNode* get_root() {
      return nodes[0];
    }
    vector<TreeNode*> nodes;
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */

int main(int argc, char const *argv[])
{
  /* code */
  TreeNode* node = new TreeNode(1);
  CBTInserter iter(node);
  cout << iter.insert(2) << endl;
  inorderDisplay(iter.get_root());
  SS_ASSERT(iter.get_root()->left == nullptr);
  return 0;
}
