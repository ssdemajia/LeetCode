#include "inc.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (!k&&!t) return false;
        set<long> s;
        for(int i = 0; i < nums.size(); i++){
            cout << "num["<<i<<"]:"<<nums[i] <<" ";
            if (i > k) s.erase(nums[i-k-1]);//维持一个k范围,每次循环就往后移一位，将最前的数去掉


            //lower_bound(x)是找出不小于x的数k，即k>=x


            auto p = s.lower_bound((long)nums[i]-t);
            //if (p == s.end()) std::cout << " Yes ";
            cout << "lower_bound:"<<*p<<"  , num:"<<nums[i]<<"  ";
            cout <<"Yo!"<< *p-nums[i] +nums[i]<<"Yo"<<endl;;
            if (p != s.end() && (*p - nums[i] <= t) ) {
                cout << "Im ";
                return true;
            }
            cout << endl;
            s.insert(nums[i]);
        }
        // for_each(s.cbegin(), s.cend(), [](const int a){cout << a<< " ";});
        // cout << endl;
        return false;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {-2147483648,-2147483647};


    Solution so;
    if (so.containsNearbyAlmostDuplicate(v, 3, 3))
    {
        std::cout << "True!" << '\n';
    }else{
        std::cout << "False" << '\n';
    }
    return 0;
}
