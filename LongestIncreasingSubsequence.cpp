#include "inc.h"
//300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        //displayVec(dp);
        int imax = INT_MIN;
        for (int a:dp) {
            if (imax < a) imax = a;
        }
        return imax;
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int>::iterator s = nums.begin();//s表示最小元素序列的最后一个元素迭代器位置
        for (int val : nums) {
            auto smaller = lower_bound(nums.begin(), s, val);
            //找到一个 i < val < smaller,将smaller的数变为val不会改变其递增子序列的长度
            *smaller = val;
            if (s == smaller) s++;//如果smaller是最后一个数，那么val大于s指向数之前的所有数，所以可以把这个最小元素集合增加
        }
        return s-nums.begin();
    }
    // int helper(TreeNode* root) {
    //     if (!root) return 0;
    //     int val = max(helper(root->left), helper(root->right)+1);
    //     cout << "root:" << root->val <<", " << val <<endl;
    //     return val;
    // }
    // TreeNode* createBST(vector<int>& nums) {
    //     TreeNode* root = NULL;
    //     for (int i : nums) {
    //         cout << "i:"<<i<<endl;
    //         insertNode(root, i);
    //     }
    //     return root;
    // }
    // void insertNode(TreeNode * &root, int val) {
    //     if (root == NULL) {
    //         root = new TreeNode(val);
    //         return;
    //     }
    //     TreeNode* parent = NULL;
    //     TreeNode*temp = root;
    //     while(temp) {
    //         parent = temp;
    //         if (temp->val < val) {
    //             temp = temp->right;
    //         }
    //         else if (temp->val > val){
    //             temp = temp->left;
    //         }
    //         else {
    //             return;
    //         }
    //     }
    //     temp = new TreeNode(val);
    //     if (parent->val > val) {
    //         parent->left = temp;
    //     }
    //     else {
    //         parent->right = temp;
    //     }
    // }
};
int main() {
    Solution so;
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    
    //inorderDisplay(root);
    cout << so.lengthOfLIS(nums1) << endl;
    return 0;
}
