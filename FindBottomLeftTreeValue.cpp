#include "inc.h"
//513. Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        int deep = Deep(root);
        vector<int>result;
        helper(root, result, 1, deep);
        return result[0];
    }
    void helper(TreeNode* root, vector<int>& result, int deep, int &Deep) {
        if (!root) return;
        if (deep == Deep && result.empty()) result.push_back(root->val);
        helper(root->left, result, deep+1, Deep);
        helper(root->right, result, deep+1, Deep);
    }
    int Deep(TreeNode* root) {
        if (!root) return 0;
        return max(Deep(root->left), Deep(root->right)) + 1;
    }
};   
int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* q1 = new TreeNode(1);
    TreeNode* q2 = new TreeNode(4);
    TreeNode* q3 = new TreeNode(5);
    root->left = q1;
    root->right = q2;
    q1->left = q3;
    Solution so;
    cout <<so.findBottomLeftValue(root)<<endl;
    return 0;
}