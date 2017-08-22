#include "inc.h"
//501. Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        int maxfreq, curfreq, pre;
        max_freq(root, maxfreq=0, curfreq=0, pre=-1);
        max_elem(root, maxfreq, curfreq=0, pre=-1);
        return result;
    }
private:
    vector<int> result;
    void max_freq(TreeNode* root, int &maxfreq, int &curfreq, int &pre) {
        if (!root) return;
        max_freq(root->left, maxfreq, curfreq, pre);
        curfreq = root->val==pre?++curfreq:0;//如果当前数等于前一个数，那么当前的频率增加
        pre = root->val;//pre保存前一个数
        maxfreq = max(maxfreq, curfreq);//与最大频率作比较，保存最大频率
        max_freq(root->right, maxfreq, curfreq, pre);
    }
    void max_elem(TreeNode* root, int maxfreq, int &curfreq, int &pre) {
        if (!root) return;
        max_elem(root->left, maxfreq, curfreq, pre);
        curfreq = root->val==pre?++curfreq:0;
        pre = root->val;
        if (curfreq == maxfreq) result.push_back(root->val);//如果当期频率等于最大频率，则加入到结果中
        max_elem(root->right, maxfreq, curfreq, pre);
    }
};
int main() {
    TreeNode* root = new TreeNode(2147483647);
    //TreeNode* p1 = new TreeNode(2);
    //TreeNode* p2 = new TreeNode(2);
    //p2->left = p1;
    //root->right = p2;
    Solution so;
    displayVec(so.findMode(root));
    return 0;
}