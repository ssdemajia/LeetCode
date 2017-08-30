#include "inc.h"
//662. Maximum Width of Binary Tree
/**
 * Definition for a binary tree node.
 struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    int widthOfBinaryTree2(TreeNode* root) {//Time Limit
        deque<TreeNode *> q;//使用层序遍历
        q.push_back(root);
        int wid = 1;
        int curWid = 1;
        int i= 0;
        while(!q.empty()) {
            i++;
            TreeNode * temp = q.front();
            q.pop_front();
            
            if (temp) {
                q.push_back(temp->left);
                q.push_back(temp->right);
            }
            else {
                q.push_back(NULL);
                q.push_back(NULL);
            }
            if (i == curWid) {
                i = 0;
                curWid*=2;
                int start = 0, end = q.size()-1;
                while(start <= end&&(q[start] == NULL || q[end] == NULL)) {
                    if (q[start] == NULL) {
                        start++;
                    }
                    if (q[end] == NULL) {
                        end--;
                    }
                }
                if (start>end) return wid;
                if (end-start+1>wid) {
                    wid =end-start+1;
                }
            }
        }
        return wid;
    }
    int widthOfBinaryTree(TreeNode* root) {
        int distance = 0;
        vector<int> deeps = {};
        help(root, 0, 1, deeps, distance);
        return distance;
    }
    void help(TreeNode* root,  int deep, int No, vector<int> &deeps, int &distance) {
        if(!root) return;
        if(deep == deeps.size()) deeps.push_back(No);//如果这个深度是第一个到，则增加到deeps里
        distance = max(No-deeps[deep]+1, distance);//当前深度中储存了这个深度第一个节点的序号
        help(root->left, deep+1, 2*No, deeps, distance);
        help(root->right, deep+1, 2*No+1, deeps, distance);
    }

};
int main (){
    Solution so;
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(5);
    TreeNode *p5 = new TreeNode(6);
    TreeNode *p6 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p2->right = p4;
    p3->left = p5;
    p4->right = p6;
    cout << so.widthOfBinaryTree(root) << endl;
} 