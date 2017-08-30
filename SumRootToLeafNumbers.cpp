#include "inc.h"
//129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        helper(root, 0, result);
        return result;
    }
    void helper(TreeNode* root, int num, int&result) {
        if (!root) return;
        num*=10;
        num+=root->val;
        if (!root->left && !root->right) {
            result+=num;
            return;
        }
        helper(root->left, num, result);
        helper(root->right, num, result);
    }
};