#include "inc.h"
class Solution {
public:
    int maxArea2(vector<int>& height) {//time limit exceed
        int result = 0;
        int len = height.size();
        for (int i = 0; i < len; i++) {
            for (int j = i+1;j<len;j++) {
                int temp = min(height[i],height[j]) * abs(j-i);
                if (temp > result) result = temp;
            }
        }

        return result;
    }
    int maxArea(vector<int>& height) {//
        int result = 0;
        int len = height.size();
        int start = 0;
        int end = len-1;
        while(start < end) {
            int temp = min(height[start],height[end]) * abs(end-start);
            if (temp > result) result = temp;
            if (height[start] < height[end]) start++;//如果有一块木板短了，应该改变它
            else end--;
        }
        return result;
    }
};
int main()
{
    vector<int> v1 = {1,7,2,3,4};
    vector<int> v2 = {1,2,1};
    unordered_map<int, vector<int>> m = {
        {12, {1,7,2,3,4}},
        {2,{1,2,1}}
    };
    Solution so;
    for (auto p = m.begin(); p != m.end(); p++) {
        int result = so.maxArea(p->second);
        if (result == p->first) {
            std::cout << "RIGHT-----";
            displayVec(p->second," ");
            cout << '\n';
        }else {
            std::cout << "WRONG!!!--";
            displayVec(p->second," ");
            cout << "right answer is"<<p->first<< " , my anwser is "<<result<<'\n';
        }
    }
    return 0;
}
