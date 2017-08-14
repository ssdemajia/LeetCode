#include "inc.h"
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    string helper(unordered_map<string, vector<TreeNode*> >& m, TreeNode* root)
    {
        //cout << root->val << endl;
        if (!root) return "";
        string s = "(" + helper(m, root->left) + to_string(root->val) + helper(m,root->right) + ")";
        m[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > m;
        helper(m, root);
        //for_each(m.begin(), m.end(), [](pair<string, vector<TreeNode*> >p){cout <<p.first<<":"<<p.second[0]->val<<" ";});
        vector<TreeNode *> result;
        for(auto p = m.begin(); p != m.end(); p++)
        {
            //cout << p->first << ":" << m.count(p->first)<<endl;
            if (p->second.size() > 1)result.push_back(p->second[0]);
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(2);
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(1);
    root->left = p1;
    root->right = p2;
    Solution so;
    vector<TreeNode*> result = so.findDuplicateSubtrees(root);
    for_each(result.begin(), result.end(), [](TreeNode* p){cout << p->val << " ";});
    cout << endl;

    return 0;
}
