#include "inc.h"
//684. Redundant Connection
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> tree;
        for (int i = 0; i < edges.size(); i++) {
            int p = edges[i][0];
            int c = edges[i][1];
            if (tree.count(p) == 0) tree[p] = p;//如果当前结点没有父结点则自己是父结点
            if (tree.count(c) == 0) tree[c] = c;//同上
            int realp = find(p,tree);//找到当前p结点的根结点
            int realc = find(c,tree);//当前c结点的根结点
            cout << "realP:" << realp << ", realc:"<<realc<<endl;
            if (realp!=realc ) {//如果两个结点不是一个集合内
                tree[realc] = realp;//则把realp作为新的根，realc作为子结点
            }
            else {
                displayMap(tree);   
                return edges[i];
            }
            //cout << 1<< endl;
            //displayMap(tree);
            //displayVec2d(result);
        }
        return {};
    }
    int find(int num, unordered_map<int, int>& dict){
        while (dict[num] != num){//找到当前结点的根结点
            dict[num] = dict[dict[num]];//同时缩短子树的高度
            num = dict[num];
        }
        return num;
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
    Solution so;
    displayVec(so.findRedundantConnection(edges3));
    return 0;
}