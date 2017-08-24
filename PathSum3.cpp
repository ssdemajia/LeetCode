#include "inc.h"
//437. Path Sum III
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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        helper(root, sum, count);
        return count;
    }
    void helper(TreeNode* root, int sum, int &count) {
        if (!root) return;
        helper(root->left, sum, count);
        helper(root->right, sum, count);      
        path(root, sum, count);
    }
    void path(TreeNode *root, int sum, int &count) {
        if (!root) return;
        if (sum-root->val==0) count++;//从root到cur的路径差等于0，则找到一条path，然后继续向下找
        path(root->left, sum-root->val, count);
        path(root->right, sum-root->val, count);            
    }
};
int main() {
    TreeNode* root = new TreeNode(10);
    TreeNode* r1= new TreeNode(5);
    TreeNode* r2 = new TreeNode(-3);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* r4 = new TreeNode(2);
    TreeNode* r5 = new TreeNode(11);
    TreeNode* r6 = new TreeNode(3);
    TreeNode* r7 = new TreeNode(-2);
    TreeNode* r8 = new TreeNode(1);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->right = r5;
    r3->left = r6;
    r3->right = r7;
    r4->right = r8;
    Solution so;
    cout << so.pathSum(root, 8)<<endl;
    return 0;
}