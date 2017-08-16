#ifndef _INC_H
#define _INC_H
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <iomanip>//操控输入输出格式
#include <unordered_map>
#include <unordered_set>
#include <bitset>
//#include <stack>
using namespace std;
using vvs = vector<vector<string>>;//定义一些简易的别名
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vs = vector<string>;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
void displayVec(std::vector<T> v, string sep = " ")
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << sep;
    }
    cout << endl;
}
template <typename T>
void displayVec2d(std::vector<std::vector<T> > v,string sep = " ")
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << sep;
        }
        cout << endl;
    }
}
template <typename K, typename V>
void displayMap(std::unordered_map<K,V> m, string sep = " ")
{
    for (auto p:m) {
        cout << p.first<<"->"<<p.second<<" ";
    }
    cout << "\n";
}
#endif
