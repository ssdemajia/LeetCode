#include "inc.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        for(auto i : prerequisites) {
            cout << i.first << i.second << endl;
        }
        return false;
    }
};
int main() {
    Solution so;
    vector<pair<int, int>> prerequire = {{0, 1}
    };
    int numCourses = 2;
    so.canFinish(numCourses, prerequire);
    return 0;
}