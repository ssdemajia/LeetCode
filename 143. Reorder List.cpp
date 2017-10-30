#include "inc.h"
//143. Reorder List
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
    思路主要是首先找到第n/2的节点，因为它之后的节点需要倒序后插入到前面
    */
    void reorderList(ListNode* head) {
        if (!head) return;
        int len = Length(head);
        int start = len/2;
        ListNode* index = head;
        ListNode* pre = NULL;
        for (int i = 0; i < start; i++) {
            pre = index;
            index = index->next;
        }
        if (!pre) return;
        for (ListNode* p = index; pre&&p; ){
            ListNode* temp = p->next;
            p->next = pre->next;
            pre->next = p;
            p = temp;
        }
        index->next = NULL;
        ListNode* head2 = pre->next;
        pre->next = NULL;
        ListNode* p = head;
        ListNode* p2 = head2;
        //cout << "p:" << p->val << ", p2:"<<p2->val<<endl;
        while (p&&p2) {
            //cout << "p:" << p->val << ", index:"<<index->val<<endl;
            ListNode* temp = p->next;
            ListNode* temp2 = p2->next;
            p->next = p2;
            if (temp) p2->next = temp;
            p = temp;
            p2=temp2;
        }
        
    }
private:
    int Length(ListNode* node) {
        int result = 0;
        while (node) {
            result++;
            node = node->next;
        }
        return result;
    }
};
int main(){
    Solution so;
    ListNode* head = createList({1,2,3});
    so.reorderList(head);
    displayList(head);
    return 0;
}