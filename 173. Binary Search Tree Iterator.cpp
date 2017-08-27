#include "inc.h"
#include <stack>

//173. Binary Search Tree Iterator
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class BSTIterator {//实现一个不用递归的中序遍历
 private:
    stack<TreeNode*> s;
    TreeNode* itor;
public:
    BSTIterator(TreeNode *root){
        itor = root;
        while(itor){
            s.push(itor);
            itor=itor->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || itor;
    }

    /** @return the next smallest number */
    int next() {
        itor = s.top();
        int temp = itor->val;
        s.pop();
        itor = itor->right;
        while(itor){
            s.push(itor);
            itor=itor->left;
        }
        return temp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
    string data = "5(3(1,),7(6,8))";
    TreeNode* root = deserialize(data);
    //inorderDisplay(root);
    BSTIterator itor(root);
    while(itor.hasNext()) cout << itor.next()<<" ";
    return 0;
}