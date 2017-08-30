#include "inc.h"
//222. Count Complete Tree Nodes
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
    int countNodes2(TreeNode* root) {//使用递归
        if (!root) return 0;
        TreeNode* l = root;
        TreeNode* r = root;
        int deepl = 0, deepr = 0;//分别是最左子树的深度，最右子节点的深度
        while(l){
            l = l->left;
            deepl++;
        }
        while(r){
            r = r->right;
            deepr++;
        }
        if (deepl == deepr) return pow(2,deepl)-1;//如果两个子节点的深度一样就不需要再继续往下递归运算，而是直接用公式计算节点数
        else {
            return 1 + countNodes(root->left)+countNodes(root->right);
        }
    } 
    int countNodes(TreeNode* root) {
        int Deep = 0, result = 0;
        if (!root) return 0;
        TreeNode* temp = root, *child = root;//calculate the height of this tree
        while(temp) {
            Deep++;
            temp=temp->left;
        }
        int parentHigh = Deep;//the height of current node 
        
        while (parentHigh>1) {//parentHigh is range 2 to Deep, because 
            child = root->left;//this node's child 
            int childHigh = parentHigh-1;//the height of current node's child 
            for (int i = childHigh; i > 1; i--) child = child->right;//iterate child node from childHigh to 1
            if (child) {//if childtree is a full tree, the child isn't null, so the right child may be not a full tree
                root = root->right;//and then binary search parent's right subtree
                result += 1<<(childHigh-1);//add the count of full binary tree's leaf
            }else{//if not, after iterating child will be null.
                root=root->left;
            }
            parentHigh--;//downward the parent        
        }
        if (root) result++;//if root is full binary tree, you need add the last node
        return result + (1<<(Deep-1))-1;
    }
    
};
int main() {
    TreeNode* root = deserialize("5(4(9(6,7),1(8,)),8(7,2))");
    TreeNode* root2 = deserialize("1(2,3)");
    Solution so;
    cout << so.countNodes(root)<<endl;
}