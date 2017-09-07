#include "inc.h"
//672. Bulb Switcher II
class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0 || m == 0) return 1;
    
        if (m == 1 && n == 1) return 2;
        if (m == 1 && n == 2) return 3;
        if (m == 1 && n == 3) return 4;
        if (m == 2 && n == 1) return 2;
        if (m == 2 && n == 2) return 4;
        if (m == 2 && n == 3) return 7;
        if (m == 3 && n == 1) return 2;
        if (m == 3 && n == 2) return 4;
        if (m == 3 && n == 3) return 8;
    
        if (m >= 3 && n >= 3) return 8;
        if (m >= 3) return flipLights(n, 3);
        if (n >= 3) return flipLights(3, m);
    }
};