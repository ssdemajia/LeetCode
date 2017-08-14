#include "inc.h"
//31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int key= len-1;
        int min;
        while(key > 0) {//从右到左找到第一个不满足降序的nums[key-1]和nums[key]
            if (nums[key]>nums[key-1]) {//找到这样的一个升序
                min = key;
                for (int i = key; i < len; i++) {//从key开始到结尾寻找一个大于nums[key-1]数中最小的数
                    if (nums[key-1] < nums[i]) {
                        min = nums[i] > nums[min]?min:i;
                    }
                }
                swap(nums[min], nums[key-1]);//交换数字
                break;
            }
            key--;
        }
        reverse(nums, key, len-1);//剩下的数都是逆序的，需要将它们改为升序

    }
    void reverse(vector<int> &nums, int start, int end) {
        int temp;
        int size = end - start;
        for (int i = 0; i <= size/2; i++) {
            temp = nums[i+start];
            nums[i+start] = nums[start+size-i];
            nums[start+size-i]=temp;
        }
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums = {1,5,2,4,3};
    Solution so;
    //so.reverse(nums, 2,4);
    displayVec(nums);
    so.nextPermutation(nums);
    displayVec(nums);
    return 0;
}
