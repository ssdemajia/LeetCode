#include "inc.h"
//670. Maximum Swap
class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        int start = 0;
        // int end = nums.size()-1;
        int index = 0;
        while(start < nums.size()) {
            index = start;
            for (int i = index+1; i < nums.size(); i++) {
                if (nums[index]-'0' < nums[i]-'0') {
                    index = i;
                }
                else if (index != start && nums[index]-'0' == nums[i] - '0') {//当重复最大值时，去索引靠后的作为最大的索引
                    index = i;
                }
            }
            if (index != start) {
                swap(nums[index], nums[start]);
                break;
            }
            start++;
        }
        cout << nums<<endl;
        cout << "start:"<<start<<", index:"<<index<<endl;
        int result = stoi(nums);
        return result;
    }
};
int main(){
    Solution so;
    //input: 98368
    cout << so.maximumSwap(98368) << endl;
    return 0;
}