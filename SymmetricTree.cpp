#include "inc.h"
//101. Symmetric Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p&&!q) return true;
        if (!p || !q) return false;//不相同的情况
        bool l = helper(p->left, q->right);//分别是外面和里面
        bool r = helper(p->right, q->left);
        bool m = p->val == q->val;//根节点值相同
        return l&&m&&r;
    }
};