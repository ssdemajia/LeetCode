#include "inc.h"
//113. Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(result, temp, root, sum);
        return result;
    }
    bool helper(vector<vector<int>> &result, vector<int> &temp, TreeNode* root, int sum) {
        if (!root) return false;
        if (sum-root->val == 0 && !root->left && !root->right) {
            temp.push_back(root->val);
            result.push_back(temp);
            temp.pop_back();
            return true;
        }
        temp.push_back(root->val);
        bool l = helper(result, temp, root->left, sum-root->val);
        bool r = helper(result, temp, root->right, sum-root->val);
        temp.pop_back();
        if (!l&&!r) return false;
        return true;
    }
};