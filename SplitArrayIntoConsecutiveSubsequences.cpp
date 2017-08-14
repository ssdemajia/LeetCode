#include "inc.h"
//659. Split Array into Consecutive Subsequences
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        for (auto p : nums) count[p]++;//将每个数字的个数储存起来
        for (auto p : nums) {
            if (count[p] <= 0) continue;//如果这个数之前就已经被取出来了，那么跳过它
            if (end[p-1] > 0) {//如果比当前数小1的数结尾的子序列存在，那么直接把这个数加到那个序列后面
                end[p]++;//以当前数结尾的子序列个数加1
                end[p-1]--;//p-1的数结尾的子序列减1
                count[p]--;//当前数用于构建子序列，所以要把它的个数减1
            }
            else if (count[p+1]>0 && count[p+2]>0) {
                count[p]--;//p后面两个数还有没用过的，将它们取出来
                count[p+1]--;
                count[p+2]--;
                end[p+2]++;//那么p+2结尾的子序列个数加1
            }else {//如果不满足个数大于2的子序列大小，那么返回false
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    Solution so;
    std::vector<int> v = {1,2,3,4,5,5};
    
    if(so.isPossible(v)){
        cout << "Yes!!!!" << endl;
    } else {
        cout << "No!!!!"<<endl;
    }
    return 0;
}
