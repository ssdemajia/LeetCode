/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //leetcode 617     合并两个二叉树
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1!=NULL&&t2!=NULL) {//遍历到的结点如果t1和t2都不是空的那么把他们相加起来，再继续遍历
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
        if (t1 == NULL && t2!=NULL)//如果t1结点是空的，而t2结点非空，
        //那么返回t2作为t1父结点的子节点，不再继续遍历下去
        {
            return t2;
        }
        if (t1 == NULL && t2 == NULL)
        {
            return NULL;
        }
        if (t1 != NULL && t2==NULL){
            t1->left = mergeTrees(t1->left, NULL);
            t1->right = mergeTrees(t1->right, NULL);
            return t1;
        }
    }
};
