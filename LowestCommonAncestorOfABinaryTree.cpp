#include "inc.h"
#include <stack>
//236. Lowest Common Ancestor of a Binary Tree
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
        vector<TreeNode*> sp;
        vector<TreeNode*> sq;
        TreeNode* r1 = root, *r2 = root;
        TreeNode* last = NULL;
        while(!sp.empty() || r1) {
            if (r1) {
                sp.push_back(r1);
                r1 = r1->left;
            }
            else {
                TreeNode * temp = sp.back();
                if (temp->right && temp->right != last) {
                    r1 = temp->right;
                }else{
                    if (temp == p) break;
                    sp.pop_back();
                    //cout << temp->val << endl;             
                    last = temp;
                }
            }
        }
        last = NULL;
        while(!sq.empty() || r2) {
            if (r2) {
                sq.push_back(r2);
                r2 = r2->left;
            }
            else {
                TreeNode * temp = sq.back();
                if (temp->right && temp->right != last) {
                    r2 = temp->right;
                }else{
                    if (temp == q) break;
                    sq.pop_back();
                    
                    
                    last = temp;
                }
            }
        }
        TreeNode* result;
        int i = 0;
        //cout << "sp:"<<sp.size() << " , sq:" << sq.size() << endl;
        while(i < sp.size() && i < sq.size()) {
            //cout << "i:"<<i<<endl;
            if (sp[i] != sq[i]) break;
            i++;
        }
        return sp[i-1];
    }
};
int main() {
    TreeNode* root = deserialize("1(,4)");
    Solution so;
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode * result = so.lowestCommonAncestor(root, new TreeNode(1), new TreeNode(4));
    cout << (result?result->val:0) << endl;
    return 0;
}