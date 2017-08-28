#include "inc.h"
#include <stack>
//145. Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* last = NULL;//last保存上一个出栈的节点
        while(!s.empty() || root) {
            if (root) {//将当前节点和左节点放入栈中
                s.push(root);
                root=root->left;
            }
            else {
                TreeNode * cur = s.top();//左节点已经到尽头，将栈顶取出                
                if (cur->right && last != cur->right) {//当前节点有右子树，并且右子树没有访问过，访问右子树
                    root = cur->right;
                }
                else {//从右子树返回，那么把当前节点放入结果中，last为当前节点，栈弹出
                    result.push_back(cur->val);
                    last = cur;
                    s.pop();
                }
                         
            }
        }
        return result;
    }
};
int main(){
    string data = "5(3(1,2),4(6,7))";
    TreeNode * root= deserialize(data);
    //inorderDisplay(root);
    Solution so;
    displayVec(so.postorderTraversal(root));
    return 0;
}