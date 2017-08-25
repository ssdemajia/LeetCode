#include "inc.h"
//508. Most Frequent Subtree Sum
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        helper(root, m);
        int max = 0;
        for (auto p:m){
            if (p.second >= max){
                max = p.second;
            }
        }
        vector<int> result;
        for (auto p:m) {
            if (p.second == max) {
                result.push_back(p.first);
            }
        }
        return result;
    }
    int helper(TreeNode* root, unordered_map<int, int> &m) {
        if (root) {
            int l = helper(root->left, m);
            int r = helper(root->right, m);
            m[l+r+root->val]++;//将子树和放入map中
            return l+r+root->val;
        }
        return 0;
    }
};