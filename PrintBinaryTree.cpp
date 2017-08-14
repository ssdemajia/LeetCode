#include "inc.h"
//leetcode 655
// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = deep(root);//求出当前树的深度
        int width = pow(2, depth) - 1;//根据深度求出叶子的数量
        vector<vector<string> > result (depth, vector<string>(width, ""));//构建二维数组
        helper(root, result, 0, 0, width-1);
        return result;
    }
    void helper(TreeNode* root, vector<vector<string> > &result,int deep, int left, int right) {
        if (root){
            int index = (right-left)/2;//求出当前结点在这个深度的列
            result[deep][index] = to_string(root->val);
            if (root->left) {//左子树存在时递归遍历，深度加1,左边界不变，右边界变为中间
                helper(root->left,result, deep+1, left, index-1);
            }
            if (root->right) {
                helper(root->right, result, deep+1, index+1, right);
            }
        }

    }
    int deep(TreeNode *root) {//求树深度的方法
        if (!root) return 0;
        int ld = deep(root->left);
        int rd = deep(root->right);
        return ld>rd?ld+1:rd+1;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    root->left = p1;
    displayVec2d(so.printTree(root));
    return 0;
}
