#include "inc.h"
//235. Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while (!(root->val <= q->val && root->val >= p->val)) {//根据根节点与左右节点的值，来选择下一个根节点
            if (root->val > q->val) {
                root=root->left;
            }else if (root->val < p->val) {
                root=root->right;
            }
        }
        return root;
    }
    
};
int main(){
    Solution so;
    TreeNode* root = new TreeNode(6);
    TreeNode* q1 = new TreeNode(2);
    TreeNode* q2 = new TreeNode(8);
    root->left = q1;
    root->right = q2;

    TreeNode* q3 = new TreeNode(0);
    TreeNode* q4 = new TreeNode(4);
    q1->left = q3;
    q1->right = q4;

    TreeNode* q5 = new TreeNode(3);
    TreeNode* q6 = new TreeNode(5);
    q2->left = q5;
    q2->right = q6;

    cout << (so.lowestCommonAncestor(root, q4, q6))->val << endl;
    return 0;
}