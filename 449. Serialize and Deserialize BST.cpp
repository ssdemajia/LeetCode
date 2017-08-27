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
 class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "*";
        return to_string(root->val)+"("+serialize(root->left)+","+serialize(root->right)+")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "*") return NULL;
        int mid;
        for (mid = 0; mid < data.size(); mid++) {
            if (data[mid] == '(')break;//找到第一个括号
        }
        //cout << "data:"<<data<< " ,mid:"<<mid<<endl;
        string rs = data.substr(0, mid);//根节点的值
        TreeNode* root = new TreeNode(stoi(rs));
        int i,j = 0;
        for (i = 1; i < data.size(); i++) {
            if (data[i] == '(') j++;
            else if (data[i] == ')') j--;
            if (j == 1 && data[i] == ',') break;//找到左子树和右子树的中间，是： 根(左子树根(左子树的左右子树。。),右子树根(右子树的左右子树。。))
        }
        //cout << "i:" << i << ", j:" << j<<endl;
       // cout << "data.sub:"<<data.substr(2, i-2)<<endl;
        root->left = deserialize(data.substr(mid+1, i-mid-1));
        root->right = deserialize(data.substr(i+1, data.size()-i-2));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(){
    TreeNode* root = new TreeNode(25);
    TreeNode* p1 = new TreeNode(12);
    TreeNode* p2 = new TreeNode(37);
    root->left = p1;
    root->right = p2;
    TreeNode* p3 = new TreeNode(14);
    p1->right = p3;
    TreeNode* p4 = new TreeNode(15);
    p3->right = p4;
    Codec so;
    cout << so.serialize(root) << endl;
    so.deserialize(so.serialize(root));
    return 0;
}