#include "inc.h"
//623. Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return root;
        return helper(root, v, d, 1);
    }
    TreeNode* helper(TreeNode* root, int v, int d, int cur) {
        if (!root) return NULL;
        if (d==1) {
            TreeNode* temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }
        else if (cur == d-1) {
            TreeNode* p1 = new TreeNode(v);
            TreeNode* p2 = new TreeNode(v);
            p1->left = root->left;
            p2->right = root->right;
            root->left = p1;
            root->right = p2;
            return root;
        }
        else {
            helper(root->left, v, d, cur+1);
            helper(root->right, v, d, cur+1);
        }
        return root;
    }
};