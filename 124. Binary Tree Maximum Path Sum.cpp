#include "inc.h"
//124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int maxpath = 0;
        helper(root, maxpath);
        return maxpath;
    }
    int helper(TreeNode* root, int &maxpath) {
        if (!root) return 0;
        int l = max(0,helper(root->left, maxpath));//如果左子树返回的是一个负数，那么就不考虑它
        int r = helper(root->right, maxpath);//同上
        maxpath = max(maxpath, root->val+l+r);//当root作为结束的根节点时，获得的路径和
        return max(l,r)+root->val;//返回以这个根节点加最大子树和的和
    }
};