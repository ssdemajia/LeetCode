#include "inc.h"
//666. Path Sum IV
class Solution {
public:
    int pathSum(vector<int>& nums) {
        map<int, map<int,int>> m;
        for (int i : nums) {
            int deep = i/100;//将数分解成三部分
            int position  = i/10%10;
            int value = i%10;
            m[deep][position] = value+m[deep-1][(position+1)/2];//计算从根节点到当前节点的路径和
        }
        //cout <<m[0][1]<<endl;
        int result = 0;
        //cout << m.size() << ", "<<m[1].size() << endl;
        for (int i = 1; i < m.size(); i++) {
            for (int j = 1; j <= m[i].size(); j++) {
                if (m[i][j] && !m[i+1][j*2] && !m[i+1][j*2-1]) {//这个节点是一个叶节点
                    result+=m[i][j];
                }
            }
        }
        return result;
    }
    
};
int main(){
    vector<int> nums = {113, 215, 221};
    vector<int> nums2 = {113, 221};
    vector<int> nums3 = {111,217,221,315,415};
    Solution so;
    cout << so.pathSum(nums3) << endl;
    return 0;
}