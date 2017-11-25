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
#include <queue>
#include <deque>
//#include <stack>
using namespace std;
using vvs = vector<vector<string>>;//定义一些简易的别名
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vs = vector<string>;
struct TreeNode {//树节点
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {//链表节点
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> nums) {//通过vector建立list
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    for (int i : nums) {
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = temp->next;
    }
    return head->next;
}
void displayList(ListNode* l) {//打印list
    while(l) {
        cout << l->val << " ";
        l=l->next;
    }
    cout << endl;
}



template <typename T>//打印vector
void displayVec(std::vector<T> v, string sep = " ")
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << sep;
    }
    cout << endl;
}
template <typename T>//打印二维vector
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
void displayMap(std::unordered_map<K,V> m, string sep = " ")//打印map
{
    for (auto p:m) {
        cout << p.first<<"->"<<p.second<<" ";
    }
    cout << "\n";
}

string serialize(TreeNode* root) {//序列化一个二叉树
    if (!root) return "";
    return to_string(root->val)+"("+serialize(root->left)+","+serialize(root->right)+")";
}

//通过string来构建一个tree，格式：根(左子树根(左子树的左右子树。。),右子树根(右子树的左右子树。。))
/* 
例如 1(2(,),3(,)) 表示        1
                          /    \
                         2     3
 2(3(4(2,3),),) 表示 2
                   /    
                  3 
                 /
                4
              /  \
             2   3

 */
TreeNode* deserialize(string data) {//前序构造遍历来构造树，通过括号来分割
    if (data.size() == 0) return NULL;
    if (data[data.size()-1] != ')'){//如果data是纯数字，那么直接构造一个节点并且返回
        TreeNode* root = new TreeNode(stoi(data));
        return root;
    }
    int mid;
    for (mid = 0; mid < data.size(); mid++) {
        if (data[mid] == '(')break;//找到第一个括号
    }
    string rs = data.substr(0, mid);//根节点的值
    TreeNode* root = new TreeNode(stoi(rs));
    int i,j = 0;
    for (i = 1; i < data.size(); i++) {
        if (data[i] == '(') j++;
        else if (data[i] == ')') j--;
        if (j == 1 && data[i] == ',') break;//找到左子树和右子树的中间，是： 根(左子树根(左子树的左右子树。。),右子树根(右子树的左右子树。。))
    }
    root->left = deserialize(data.substr(mid+1, i-mid-1));
    root->right = deserialize(data.substr(i+1, data.size()-i-2));
    return root;
}
void inorderDisplay(TreeNode* root) {
    if (!root) return;
    inorderDisplay(root->left);
    cout << root->val<<" ";
    inorderDisplay(root->right);
}

#define SS_ASSERT(CONDITION) do{if(!(CONDITION))\
                {cout << __LINE__ <<":error!"<<endl;}\
                else\
                {cout<<"Yes!"<<endl;}}while(0)
#define TEST_ASSERT(CONDITION) do{if(!(CONDITION))throw 0;}while(0)
#define TEST_PRINT(MESSAGE) cout<<(MESSAGE)<<endl;
#endif
