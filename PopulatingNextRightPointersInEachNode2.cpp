#include "inc.h"
//Populating Next Right Pointers in Each Node II
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode* cur;
        while(!q.empty()) {
            queue<TreeLinkNode*> temp;//保存下一行的节点
            while(!q.empty()) {
                cur = q.front();
                q.pop();
                cur->next = q.empty()?NULL:q.front();
                if (cur->left) temp.push(cur->left);
                if (cur->right) temp.push(cur->right);
            }
            q = temp;
        }
    }
};