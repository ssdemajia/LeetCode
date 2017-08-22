#include "inc.h"
#include <stack>
//98 Validate Binary Search Tree
class Solution {
public:
    bool isValidBST2(TreeNode* root) {//使用中序遍历将所有节点放入mid向量中
        vector<int> mid;
        helper(mid,root);
        for (int i = 1; i < mid.size(); i++) {
            if (mid[i-1] >= mid[i]) return false;
        }
        return true;
    }
    void helper(vector<int> &mid, TreeNode* root) {
        if (root) {
            helper(mid, root->left);
            mid.push_back(root->val);
            helper(mid, root->right);
        }
    }
    bool isValidBST(TreeNode* root) {//使用栈来模拟中序遍历
        stack<TreeNode*> s;
        TreeNode* last = NULL;//用来保存中序遍历的上一个节点
        while(!s.empty()||root!=NULL) {
            if (root!=NULL) {//一直往左子树走直到走不下去
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                if (last && last->val > root->val) return false;
                last = root;
                s.pop();
                root=root->right;
            }
        }
        return true;
    }
};
int main()
{
    TreeNode * root = new TreeNode(2);
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(3);
    root->left = p1;
    root->right = p2;
    Solution so;
    if (so.isValidBST(root)) cout << "Yes!!"<<endl;
    else cout << "No!!!"<<endl;
    return 0;
}