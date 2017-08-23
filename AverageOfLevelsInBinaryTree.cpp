#include "inc.h"
//637. Average of Levels in Binary Tree
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
    // vector<double> averageOfLevels(TreeNode* root) {//Too slow
    //     vector<double> result;
    //     map<int, vector<int>> deeps;
    //     helper(deeps, root, 0);
    //     for (auto itor = deeps.begin(); itor != deeps.end(); itor++) {
    //         double sum = 0;
    //         for (int i = 0; i < itor->second.size(); i++){
    //             sum+=itor->second[i];
    //         }
    //         result.push_back(sum/itor->second.size());
    //     }
    //     return result;
    // }
    // void helper(map<int, vector<int>> &deeps, TreeNode* root, int deep) {
    //     if(!root) return;
    //     deeps[deep].push_back(root->val);
    //     helper(deeps, root->left, deep+1);
    //     helper(deeps, root->right, deep+1);
    // }
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<double> result;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                root = q.front();  
                sum+=root->val;  
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }

};
int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(-3);
    root->left = p1;
    p1->left = p2;
    Solution so;
    displayVec(so.averageOfLevels(root));
    return 0;
}