#include "inc.h"
//86. Partition List
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
    /* 
    思路：因为要求需要保持原来的顺序所以不能用swap，直接搞两个子序列就行，最后在合并
    */
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = new ListNode(0);
        ListNode* gt = new ListNode(0);
        ListNode* p = head;
        ListNode* index = le;
        ListNode* index2 = gt;
        while(p) {
            if (p->val < x) {
                le->next = p;
                le = le->next;
            }else {                
                gt->next = p;
                gt = gt->next;
            }
            p = p->next;
        }

        gt->next = NULL;
        le->next= index2->next;;
        return index->next;
    }
};
int main() {
    Solution so;
    ListNode* h = createList({1,4,3,2,5,2});
    ListNode* h1 = createList({1});
    displayList(so.partition(h1, 1));
    return 0;
}