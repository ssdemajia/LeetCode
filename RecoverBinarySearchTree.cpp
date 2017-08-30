#include "inc.h"
#include <stack>
//99. Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* last = NULL;
        TreeNode* a = NULL;
        TreeNode* b = NULL;
        
        TreeNode* cur = root;
        
        while(!s.empty()||cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                if (last && last->val > cur->val) {
                    a = last;
                    break;
                }
                last = cur;
                s.pop();
                cur = cur->right;
            }
        }
        cur = root;
        last = NULL;
        while(!s.empty()||cur) {
            if (cur) {
                s.push(cur);
                cur = cur->right;
            }
            else {
                cur = s.top();
                if (last && last->val < cur->val) {
                    b = last;
                    break;
                }
                last = cur;
                s.pop();
                cur = cur->left;
            }
        }
        swap(b->val, a->val);
    }
};
int main(){
    TreeNode* root = deserialize("0(1,)");
    TreeNode* root2 = deserialize("5(6(2,4),7(3,8))");
    Solution so;
    inorderDisplay(root);
    cout << endl;
    so.recoverTree(root);
    inorderDisplay(root);
}