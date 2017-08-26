#include "inc.h"
//337. House Robber III
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int l = 0; int r = 0;        
        return helper(root, l, r);
    }
    int helper(TreeNode* root, int &l, int &r) {//l,r分别是root的左右子树
        if (!root) return 0;
        int result = 0;
        int ll=0,lr=0,rl=0,rr=0;
        l = helper(root->left, ll, lr);//左右子树由孙子树获得
        r = helper(root->right, rl, rr);
        return max(l+r, root->val+ll+lr+rl+rr);
    }
};