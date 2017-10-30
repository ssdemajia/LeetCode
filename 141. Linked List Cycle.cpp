#include "inc.h"
//141. Linked List Cycle
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
    思路：使用两个指针，第一个指针慢慢的走， 第二个指针每次走两个节点，
    如果两个指针相遇说明有圈，否则第二个节点走到空指针，也就是链表最后
    */
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow&&fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
            if (fast == slow) return true;
        }
        if (slow && !fast) return false;
        return false;
    }
};
int main (){
    ListNode* head = createList({1,2,3,4,5});
    head->next->next->next = head;
    Solution so;
    if (so.hasCycle(head))  cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}