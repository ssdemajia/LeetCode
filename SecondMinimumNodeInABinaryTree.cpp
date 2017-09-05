#include "inc.h"
#include <stack>
//671. Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root) {
        stack<TreeNode*> s;
        int min = -1;
        int second = -1;
        while(!s.empty() || root) {
            if (root) {
                s.push(root);
                root=root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                if (min == -1) {
                    min = root->val;
                }
                else if (root->val < min) {
                    second = min;
                    min = root->val;
                }else if (second == -1&& root->val != min) {
                    second = root->val;
                }else if (root->val < second&& root->val != min) {
                    second = root->val;
                }
                root = root->right;
            }
        }
        return second;
    }
};