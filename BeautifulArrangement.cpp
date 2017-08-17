#include "inc.h"
//526. Beautiful Arrangement
class Solution {
public:
    int countArrangement(int N) {
        vector<int> temp;
        for (int i = 1; i <= N; i++) {
            temp.push_back(i);
        }
        int count = 0;
        helper(temp, count, 0);
        return count;
    }
    void helper(vector<int> &cur, int& count, int index){       
        if (cur.size() == index) {
            ++count;
            return;
        }
        for (int i = index; i < cur.size(); i++) {
            swap(cur[i], cur[index]);
            if (cur[index] % (index+1)==0 || (index+1) % cur[index]==0){
                displayVec(cur);
                helper(cur, count, index+1);
            }
            swap(cur[i], cur[index]);
        }
    }
};
int main(){
    Solution so;
    cout << so.countArrangement(4) << endl;
    return 0;
}