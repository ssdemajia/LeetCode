#include "inc.h"
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
    bool checkEqualTree(TreeNode* root) {
        unordered_multiset<int> s;//使用multiset因为有可能很多节点的和是一样的
        int rvalue = sum(root, s);//整个树的总和
        if (s.size() <= 1) return false;
        if (rvalue%2 == 0 && s.find(rvalue/2)!=s.end()) return true;
        return false;
    }
    int sum(TreeNode *root, unordered_multiset<int> &s) {
        if (!root) return 0;
        int lvalue = sum(root->left, s);//左子树的总和
        int rvalue = sum(root->right, s);//右子树的总和
        int mvalue = lvalue+rvalue+root->val;//当前节点的和
        s.insert(mvalue);
        return mvalue;
    }
};
int main(){
    Solution so;
    TreeNode * root = new TreeNode(0);
    TreeNode *p1 = new TreeNode(0);
    //TreeNode *p2 = new TreeNode(2);
    root->right = p1;
    //p1->left = p2;
    if(so.checkEqualTree(root)) cout << "Yes!!"<<endl;
    else cout << "No!!"<<endl;
    return 0;
}