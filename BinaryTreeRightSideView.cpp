#include "inc.h"
//199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);
        int base = 1;
        int newBase=0;
        int index = 0;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            index++;
            if(temp->left) {
                q.push(temp->left);
                newBase++;
            }
            if (temp->right) {
                q.push(temp->right);
                newBase++;
            }
            if (index == base) {
                index = 0;
                base = newBase;
                newBase = 0;
                result.push_back(temp->val);
            }
        }   
        return result;   
    }
};
int main() {
    
}