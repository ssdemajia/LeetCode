#include <stack>
#include "inc.h"
//ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0;
        int in = 0;
        stack<TreeNode*> s;//s中保存当前的根节点，和之前的根结点
        TreeNode* last = nullptr;
        TreeNode* root;
        bool isleft = true;
        while(pre!=preorder.size()) {
            if (!s.empty() && s.top()->val == inorder[in]) {
                last = s.top();
                isleft = false;//找到前序和后续遍历中对应的根节点，则要改变根节点与子树的连接方式
                s.pop();
                in++;
            }else {//首先将所有left放入栈中，直到最左边的叶节点，也就是inorder中的树的第一个节点，将其用x->left = y来连接
                TreeNode* temp = new TreeNode(preorder[pre]);
                if (pre == 0) root = temp;
                if (isleft) {//当前节点是前一节点的左子树
                    if (last) last ->left = temp;//将左子树都遍历一道
                }
                else {
                    isleft = true;//若已经访问到根节点，则last是根节点，当前节点是根节点的右子树
                    last->right = temp;            
                }
                last = temp;//last保存前一个遍历的节点， 在先序中也就是父节点
                s.push(temp);//将父节点保存，如果其没有子节点，那么会在下一个循环中弹出栈
                pre++;
            }
        }
        return root;
    }
};
int main(){
    vector<int> preorder = {5,3,1,4,7,8};
    vector<int> inorder = {1,3,4,5,7,8};
    Solution so;
    inorderDisplay(so.buildTree(preorder, inorder));
    cout << endl;
    vector<int> preorder1 = {1,2,3};
    vector<int> inorder1 = {1,3,2};
    inorderDisplay(so.buildTree(preorder1, inorder1));

    return 0;
}