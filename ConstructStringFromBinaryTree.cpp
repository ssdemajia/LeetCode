#include "inc.h"
//606. Construct String from Binary Tree
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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string root = to_string(t->val);
        if (!t->left && !t->right) return root;
        if (t->left && !t->right) return root+"("+tree2str(t->left)+")";
        else if (!t->left && t->right) return root+"()"+"("+tree2str(t->right)+")";
        else return root+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";
    }
};