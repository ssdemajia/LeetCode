#include "inc.h"
//669. Trim a Binary Search Tree
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        TreeNode* l = trimBST(root->left,L,R);
        TreeNode* r = trimBST(root->right, L,R);
        if (root->val < L || root->val > R) {
            if (l && r) {
                root->val = l->val;
                root->left = l->left;
                TreeNode* temp = l->right;
                while(temp->left) temp = temp->left;
                temp->left = l->right;
            }
            else if (!l && r) {
                root->val = r->val;
                root->left = r->left;
                root->right = r->right;
            }
            else if (l && !r) {
                root->val = l->val;
                root->left = l->left;
                root->right = l->right;
            }
            else {
                return NULL;
            }
        }
        else {
            root->left = l;
            root->right = r;
        }
        return root;
    }
};