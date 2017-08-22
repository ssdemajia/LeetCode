#include "inc.h"
//95. Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return gen(1,n);
    }
    vector<TreeNode*> gen(int start, int end) {
        if (start > end) return {NULL};//这是空树的情况
        if (start == end) return {new TreeNode(start)};//只有一个节点的情况
        vector<TreeNode*> lTree, rTree;//保存左右子树的各种组合
        vector<TreeNode*> result;//当前根的组合
        TreeNode * root;
        for (int i = start; i <= end; i++) {//选择根节点
            lTree = gen(start, i-1);
            rTree = gen(i+1, end);
            for (TreeNode* l:lTree){//遍历左组合
                for(TreeNode* r:rTree) {//遍历右子树组合
                    root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};