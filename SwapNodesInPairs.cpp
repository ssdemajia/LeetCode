#include "inc.h"
#include "../list.h"
//leetcode 24 Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if (!head) return NULL;
       ListNode *p = head;
       ListNode *pre = NULL;
       ListNode *after = NULL;
       while(p->next)
       {
           if (pre) pre->next = p->next;
           after = p->next->next;
           if (!pre) head = p->next;
           p->next->next = p;
           p->next = after;
           pre = p;
           if (after) p = after;
       }
       return head;
   }
};
void show(ListNode * head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
{
    std::vector<int> v = {1,2,3,4};
    List list(v);
        // ListNode *l2 = new ListNode(2);

    Solution so;
    //show(so.swapPairs(list.getHead()));
    //list.displayList();
}
