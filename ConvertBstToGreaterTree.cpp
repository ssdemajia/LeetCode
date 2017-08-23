#include "inc.h"
#include <stack>
//538. Convert BST to Greater Tree
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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> s;
        TreeNode* result = root;
        TreeNode* last = NULL;
        while(!s.empty() || root) {
            if (root){
                s.push(root);
                root = root->right;
            }else{
                root = s.top();
                if (last){
                    root->val+=last->val;
                }
                s.pop();
                last = root;
                root = root->left;
            }
        }
        return result;
    }
};