#include "inc.h"
//23. Merge k Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
public:
    ListNode* mergeKLists2(vector<ListNode*>& lists) {//这个方法太慢了
        ListNode* result = NULL;
        for (ListNode* l : lists) {
            displayList(l);
            if (result == NULL) result = l;
            else result = merge(result, l);
        }
        return result;
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        while(a && b) {
            if (a->val > b->val) {
                temp->next = b;
                b = b->next;
            }
            else {
                temp->next = a;
                a = a->next;
            }
            temp = temp->next;
        }
        if (a) {
            temp->next = a;
        }
        if (b) {
            temp->next = b;
        }
        return head->next;
    }


    ListNode* mergeKLists1(vector<ListNode*>& lists) {//这个方法将每个结点中最小的头取出来
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int min_node = 0;
        int p = 0;
        int node_num = total(lists);
        for (int i = 0; i < node_num; i++) {
            min_node = INT_MAX;
            for (int j = 0; j < lists.size(); j++) {//从lists中选出一个结点最小的
                if (lists[j]&&lists[j]->val < min_node) {
                    min_node = lists[j]->val;
                    p = j;
                }
            }
            result->next = lists[p];
            result = result->next;
            lists[p] = lists[p]->next;
        }
        return head->next;
    }
    int total(vector<ListNode*>& lists) {
        int sum = 0;
        for (ListNode* i : lists) {
            while (i) {
                sum++;
                i = i->next;
            }
        }
        return sum;
    }
    ListNode* mergeKLists3(vector<ListNode*>& lists) {//使用优先队列，push和pop用时logn
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        auto fun = [](ListNode*&a, ListNode*&b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(fun)> q(fun);
        for (ListNode* l: lists) {
            if (l) q.push(l);
        }
        while(!q.empty() && q.top()) {
            temp->next = q.top();
            temp = temp->next;
            if (q.top()->next) q.push(q.top()->next);
            q.pop();
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {//使用分治的策略，对list两两合并
        if (lists.size() == 0) return NULL;
        int interval = 1;//间隔
        while(interval < lists.size()) {//间隔小于lists.size说明还能归并
            for (int i = 0; i + interval < lists.size(); i+=2*interval) {
                lists[i] = merge(lists[i], lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
};
int main() {
    ListNode* list1 = createList({-2});    
    ListNode* list2 = createList({-3,-2,1});
    ListNode* list3 = NULL;
    ListNode* list4 = NULL;
    Solution so;
    vector<ListNode*> lists = {list3, list1, list2};
    ListNode* result = so.mergeKLists(lists);
    displayList(result);
    return 0;
}