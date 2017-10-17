#include "inc.h"
//61. Rotate List
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
    思路：因为当k大于list size 时需要对其取余，所以要先求长度，然后类似问题寻找右边第k个节点，
    对其进行指针操作
    */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *p = head, *index = head;
        int count = 0;
        k %= len(head);
        while (p->next) {
            //cout <<"p:"<< p->val << '\n';
            if (count < k) {
                count++;

            }else {
                index=index->next;
                
            }
            p=p->next;
        }
        if (count < k) return head;
        //cout << index->val << endl;
        p->next = head;
        head = index->next;
        index->next = NULL;
        return head;
    }
    int len(ListNode* head) {
        int result = 0;
        while(head) {
            head = head->next;
            result++;
        }
        return result;
    }
};
int main() {
    ListNode* head = createList({1,2,3,4,5});
    Solution so;
    ListNode* head2 = createList({1,2});
    //displayList(head);
    displayList(so.rotateRight(head2, 3));
    return 0;
}