#include "inc.h"
//138. Copy List with Random Pointer
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
    /* 
    思路：将新加入的节点放到对应的节点后面，这样需要一遍遍历来加入新节点，
    第二遍用来建立新节点的random指针，第三遍修复原来的节点
    */
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* p2, *p1;
        for (p2 = head; p2; p2 = p2->next)
        {
            RandomListNode* temp = new RandomListNode(p2->label);
            temp->next = p2->next;
            p2->next = temp;
            p2 = p2->next;
        }

        for (p1 = head, p2 = head->next; p1&&p2;){
            if (p1->random) p2->random = p1->random->next;
            p1 = p2->next;
            if (p1) p2 = p1->next;
        }

        RandomListNode* result = head->next;
        for (p1 = head, p2 = result; p2&&p1;) {
            p1->next = p2->next;
            p1 = p2->next;
            if (p1) p2->next = p1->next;
            p2 = p2->next;
        }

        return result;
    }
};
int main() {
    Solution so;
    RandomListNode* p1 = new RandomListNode(-1);
    RandomListNode* p2 = new RandomListNode(-1);
    p1->next = p2;
    RandomListNode* result = so.copyRandomList(p1);
    return 0;
}