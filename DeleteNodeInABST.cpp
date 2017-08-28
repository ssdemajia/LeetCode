#include "inc.h"
#include <stack>
//450. Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        TreeNode* l = deleteNode(root->left, key);
        TreeNode* r = deleteNode(root->right, key);
        if (root->val == key) {
            if (l) {//如果存在左子树，那么把它提上root的位置来，并且把右子树放到左子树里
                TreeNode* newL = l;//newL是新的当前根节点
                while(l->right) l = l->right;
                l->right = root->right;
                return newL;
            }else if (!l && r) {//如果没有左子树，只有右子树，那就直接把右子树作为新的根节点
                return r;
            }else {
                return NULL;
            }
        }
        root->left = l;//如果当前节点的值与key不相等，那么左右子树需要更新
        root->right = r;
        return root;
        
    }
};