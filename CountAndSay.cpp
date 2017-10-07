#include "inc.h"
//38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            char obj = result[0];
            int count = 1;
            string temp = "";
            for (int i = 1; i < result.size(); i++) {
                if (result[i] == obj) {
                    count++;
                }
                else {
                    temp += to_string(count)+obj;
                    obj = result[i];
                    count = 1;
                }
            }
            temp+=to_string(count)+obj;
            result = temp;
        }
        return result;
    }
};
int main() {
    Solution so;
    cout << so.countAndSay(5) << endl;
    return 0;
}