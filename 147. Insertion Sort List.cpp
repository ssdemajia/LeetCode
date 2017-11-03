#include "inc.h"
// 147. Insertion Sort List
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
    思路：主要是每次都是从头开始选择插入，插入时首先比对最后那个节点（pp）的大小，大于他就不需要再从头选择插入了
    
    */
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p = head;
        ListNode* pp = NULL;
        while (p) {
            ListNode* next = p->next;
            if (pp && p->val > pp->val) {
                pp = p;
                p = next;
                continue;
            }
            ListNode* temp = head;
            ListNode* pre = NULL;
            while (temp != p && temp->val < p->val) {
                pre = temp;
                temp = temp->next;
            }
            if (temp == p) {
                pp = p;
                p = next;
                continue;
            }
            pp->next = p->next;
            if (pre == NULL) {         
                p->next = head;
                head = p;
            } else {
                p->next = pre->next;
                pre->next = p;
            }
            p = next;
        }
        return head;
    }
};
int main(){
    Solution so;
    ListNode* head = createList({3,4,0});
    displayList(so.insertionSortList(head));
    return 0;
}