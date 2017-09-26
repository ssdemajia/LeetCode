#include "inc.h"
//681. Next Closest Time
class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> times;//时间中去除：号
        for (int i = 0; i < time.size(); i++) {
            if (i == 2) continue;
            times.push_back(time[i]-'0');
        }
        vector<int> pre = times;
        sort(pre.begin(), pre.end());//pre中是升序排列的候选数字
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < pre.size(); j++) {
                if (times[i] < pre[j]) {
                    if (i == 2) {
                        if (pre[j] < 6) {//分钟的十位需要小于6
                            time[3] = pre[j] + '0';
                            time[4] = pre[0] + '0';
                            return time;
                        }
                    }
                    else if (i == 3) {
                        time[4] = pre[j] + '0';
                        return time;
                    }
                    else if (i == 1) {
                        if ((times[0] == 2 && pre[j] < 4)|| times[0] <= 1) {
                            time[1] = pre[j] + '0';
                            time[3] = pre[0] + '0';
                            time[4] = pre[0] + '0';
                            return time;
                        }
                    }
                    else {
                        if (pre[j] == 1 || (pre[j] == 2 && pre[0] < 4)) {
                            time[0] = pre[j] + '0';
                            time[1] = pre[0] + '0';
                            time[3] = pre[0] + '0';
                            time[4] = pre[0] + '0';
                            return time;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < time.size(); i++) {//如果每一位都不能满足，那么直接将所有位变成最小的哪个数
            if (i == 2) continue;
            if (times[0] == 0 && pre[0] > 2) continue;//第一位一开始是0的情况，不该边第一位
            time[i] = pre[0] + '0';
        }
        
        return time;
    }

};
int main() {
    Solution so;
    string stime1 = "01:37";
    string stime = "00:56";
    // vector<int> times = {2,3,5,9};
    // if (so.checkTime(times)) cout << "Yes"<<endl;
    cout << so.nextClosestTime(stime) << endl;
    return 0;
}