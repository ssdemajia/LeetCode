#include "inc.h"
//575. Distribute Candies
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> set;
        for (auto p : candies){
            set.insert(p);
        }
        if (set.size() > candies.size()/2) {
            return candies.size()/2;
        }else {
            return set.size();
        }
    }
};