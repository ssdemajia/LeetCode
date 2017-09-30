#include "inc.h"
//403. Frog Jump
//题目的意思是给一个数组里面有每个石头的距离，每次跳是上一次跳的k-1长度或者k+1（上次跳的距离是k）
class Solution {
public:
    bool canCross2(vector<int>& stones) {    //用带mem的回溯算法不行，有可能出现备忘录太大了
        //int step = 0;
        vector<vector<int>> mem(stones[stones.size()-1]+stones.size(), vector<int>(stones.size(),-1));

        unordered_map<int, int> m;
        for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }

        //displayMap(m);
        return helper(mem, m, stones, 0, 0);
    }
    bool helper(vector<vector<int>> mem, unordered_map<int, int> &m, vector<int>& stones, int index, int step) {
        if (index == stones.size()-1) return true;
        if (mem[index][step] != -1) return false;
        bool left,right,mid;
        int next;
        left = right = mid = false;
        
         if (step-1 > 0) {
            next = stones[index]+step-1;
            if (m.find(next) != m.end()) {
                //cout << "left"<<ind<<endl;
                left = helper(mem, m, stones, m[next], step-1);
            }
        }
        if (left) return left;
        else if (step > 1) mem[next][step-1] = 0;
        next = stones[index] + step +1;
        if (m.find(next) != m.end()) {
            right = helper(mem, m, stones, m[next], step+1);
        }
        if (right) return right;
        else mem[next][step+1] = 0;

        next = stones[index] + step;
        if (next>0 && m.find(next) != m.end()) {
            mid = helper(mem, m, stones, m[next], step);
        }
        if (mid) return mid;
        else mem[next][step] = 0;
        return false;
    }
    bool canCross(vector<int>& stones) {    //dp算法
        //int step = 0;
        unordered_map<int, unordered_set<int>> m;
        m[0].insert(0);
        for (int i = 0; i < stones.size(); i++) {
            for (auto it = m[stones[i]].begin(); it != m[stones[i]].end(); it++) {
                m[stones[i]+*it+1].insert((*it)+1);
                if (*it>1) m[stones[i]+*it-1].insert((*it)-1);
                m[stones[i]+*it].insert((*it));
                //cout << "stones[i]:"<<stones[i]<<",k+1:"<<*it+1<<",k:"<<*it<<",k-1:"<<*it-1<<endl;
            }
        }
        return m[stones.back()].size();
    }
};
int main() {
    vector<int> stones1 = {0,1,3,5,6,8,12,17};//T
    vector<int> stones2 = {0,1,2,3,4,8,9,11};//F
    vector<int> stones5 = {0,1,3,4,5,7,9,10,12};
    vector<int> stones3 = {0, 1};//F
    vector<int> stones4 = {0,1,3,6,7};//F
    vector<int> stones = {0,2147483647};
    Solution so;
    if (so.canCross(stones5)) cout << "Yes!" << endl;
    else cout << "No!" <<endl;
    return 0;
}