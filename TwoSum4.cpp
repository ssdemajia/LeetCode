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
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 class Solution {
 public:
     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         return helper(nums, 0, nums.size()-1);
     }
     TreeNode *helper(vector<int>&nums, int i, int j) {
         if (i > j) return NULL;
         int maxIndex = i;
         int maxNums = nums[i];
         cout << maxNums << "   i:"<<i<<"  j:"<<j<<endl;
         for (int k = i+1; k <= j; k++) {
             if (nums[k] > maxNums){
                 maxIndex = k;
                 maxNums = nums[k];
             }
         }
         //cout << maxNums << "   i:"<<i<<"  j:"<<j<<endl;
         TreeNode * node = new TreeNode(maxNums);
         node->left = helper(nums, i, maxIndex-1);
         node->right = helper(nums, maxIndex+1, j);
         return node;
     }
 };
int main(int argc, char const *argv[]) {
    Solution so;
    vector<int> nums = {3,2,1,6,0,5};
    so.constructMaximumBinaryTree(nums);
    return 0;
}
