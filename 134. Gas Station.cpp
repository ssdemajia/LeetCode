#include "inc.h"
//134. Gas Station
class Solution {
public:
    /* 
    思路：主要是通过起点位置i将整个路径分成了两个部分，第一个部分要尽可能的小，因为
    起点之后的路要尽可能的大来满足能够通过整个路程
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum(INT_MAX), start(0),total(0);
        for ( int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < sum) {
                sum = total;
                start = i+1;
            }
        }
        return sum < 0? -1 : start;
    }
    
};