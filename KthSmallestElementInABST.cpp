#include "inc.h"
//230. Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        stack<int> s;
        while(!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                if (--k == 0) return root->val;
                s.pop_back();
                root = root->right;
            }
        }
        return 0;
    }
};