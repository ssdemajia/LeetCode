#include "inc.h"
//328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = new ListNode(0);
        ListNode* odd = oddList;
        ListNode* evenList = new ListNode(0);
        ListNode* even = evenList;
        ListNode* index = head;
        int num = 1;
        while(index) {
            if (num%2 == 0) {
                even->next = index;
                even = even->next;
            }
            else {
                odd->next = index;
                odd = odd->next;
            }
            index = index->next;
            num++;
        }
        odd->next = evenList->next;
        even->next = NULL;
        delete evenList;
        return oddList->next;
    }
};
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    p1->next = p2;
    p2->next = p3;
    Solution so;
    so.oddEvenList(p1);
    return 0;
}