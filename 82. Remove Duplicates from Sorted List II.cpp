#include "inc.h"
//82. Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        ListNode *pre = NULL;
        if (!p) return head;
        ListNode *next = head->next;
        if (!next) return head;
        unordered_map<int, int> m;
        while(p) {
            m[p->val]++;
            p = p->next;
        }
        //displayMap(m);
        p = head;
        ListNode* temp = NULL;
        while (p) {
            temp = p->next;
            if (m[p->val]>1) {
                if (pre) {
                    delete p;
                    pre->next= temp;
                }else {
                    head = temp;
                }
                
            }else {
                pre = p;
            }
            p = temp;
        }
        return head;
    }
};
int main() {
    ListNode* head = createList({1,2,3,3,4,4,5});
    //ListNode* head1 = createList({1,1,1,2,3});
    Solution so;
    displayList(so.deleteDuplicates(head));
    return 0;
}