#include "inc.h"
#include <stack>
//106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {//使用递归的方法，比较容易
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, int istart, int iend,
                     vector<int>& postorder, int pstart, int pend) {
        if (istart > iend) return NULL;
        if (istart == iend) {
            TreeNode* root = new TreeNode(inorder[istart]);
            return root;
        }   
        TreeNode* root = new TreeNode(postorder[pend]);
        int index = 0;
        for (int i = istart; i <= iend; i++) {
            if (inorder[i] == root->val) index = i;
        }        
        
        root->left = helper(inorder, istart, index-1, postorder, pstart, pstart+index-istart-1);
        root->right = helper(inorder, index+1, iend, postorder, pstart+index-istart, pend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {//使用栈保存根节点
        int in=0;//中序vector遍历用的指示器
        int post=0;//后序vector遍历用的指示器
        stack<TreeNode*> s;
        TreeNode* cur = nullptr;
        while(post != postorder.size()) {
            if (!s.empty() && s.top()->val == postorder[post]) {//在postorder中遍历到当前节点,则当前的cur指向的是s.top()右子树
                s.top()->right = cur;
                cur = s.top();
                s.pop();
                post++;//转到postorder中的下一个节点，当前以s.top()为根的子树已经遍历完了
            }
            else
            {
                TreeNode* newRoot = new TreeNode(inorder[in]);
                newRoot->left = cur;
                cur = nullptr;
                s.push(newRoot);
                in++;
            }
        }
        return cur;
    }
};