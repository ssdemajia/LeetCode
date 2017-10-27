#include "inc.h"
//685. Redundant Connection II
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> result;
        bool hasParent = false;
        vector<int> temp;
        for (int i = 0; i < edges.size(); i++) {
            int p = edges[i][0];
            int c = edges[i][1];
            if (m.count(c) && find(m[c].begin(), m[c].end(), p) == m[c].end()) {
                temp = m[c];
                return {temp.back(),c};
            }
            m[c].push_back(p);
            if (isCycle(m, c)) return edges[i];//判断是不是圆    
        }
        return {};
    }
    bool isCycle(unordered_map<int, vector<int>> &m, int node) {
        int source = node;
        while (m.find(m[node].front()) != m.end()) {
            node = m[node].front();
            if (node == source) return true;
        }
        return false;
    }
};
int main() {
    vector<vector<int>> edges1 = {//2,3
        {1,2},
        {1,3},
        {2,3}
    };
    vector<vector<int>> edges2 = {//3,1
        {1,2},
        {1,3},
        {3,1}
    };
    vector<vector<int>> edges3 = {//anwser is 4,1
        {2,3},
        {5,2},
        {1,5},
        {4,2},
        {4,1}
    };
    vector<vector<int>> edges = {
        {5,2},
        {3,4},
        {4,3},
        {5,3},
        {1,3}
    };
    vector<vector<int>> edges4 = {{2,1},{3,1},{4,2},{1,4}};
    Solution so;
    displayVec(so.findRedundantDirectedConnection(edges1));
    return 0;
}