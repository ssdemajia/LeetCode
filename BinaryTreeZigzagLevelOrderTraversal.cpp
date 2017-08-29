#include "inc.h"
//103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        vector<int> cur;
        q.push(root);
        int base = 1;
        int newBase=0;
        int index = 0;
        bool change = true;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            index++;
            cur.push_back(temp->val);//将当前节点放入这个层的vector中
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
                if(change) {
                    reverse(cur.begin(), cur.end());
                    change = false;
                }
                else {
                    change = true;
                }
                result.push_back(cur);
                cur.clear();
            }
        }   
        return result;  
    }
};