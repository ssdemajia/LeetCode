#include "inc.h"
//92. Reverse Linked List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /* 
    思路：找到第m个节点，对之后的节点使用倒插法
    */
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p = head;
        if (!p) return NULL;
        ListNode* start = new ListNode(0);
        ListNode* prev = start;
        start->next = p;
        int count = 1;
        ListNode* left;
        ListNode* temp;
        while (p) {
            if (count < m) {
                prev = p;
            }
            temp = p->next;
            if (count > m && count <= n) {
                left->next = temp;
                p->next = prev->next;
                prev->next = p;
            }
            if (count == m) {
                left = p;
            }
            p = temp;
            count++;
        }
        return start->next;
    }
};
int main(){
    ListNode* head = createList({1});
    Solution so;
    displayList(so.reverseBetween(head, 1, 1));
    return 0;
}