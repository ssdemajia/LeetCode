#include "inc.h"
//114. Flatten Binary Tree to Linked List
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        helper(root, last);
    }
    void helper(TreeNode* root, TreeNode* &last) {
        if (!root) return;
        if (last) {
            last->right = root;
            last->left = NULL;
        }
        last = root;
        TreeNode *temp = root->right;//需要把当前节点的右子节点保存下来，因为递归下一层是会改变last的右指针
        helper(root->left, last);

        helper(temp, last);
        
    }
};
int main() {
    TreeNode* root = deserialize("3(5(2,4),7(6,8))");
    TreeNode* root2 = deserialize("1(2,3)");
    Solution so;
    so.flatten(root);
    inorderDisplay(root);
    return 0;
}