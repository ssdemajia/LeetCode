#include "inc.h"
#include "../list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Leetcode  19
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL) return NULL;
        int count = 1;
        ListNode * cur = head;
        ListNode * pre = head;
        ListNode * after = NULL;

        while (pre->next) {
            if (count == n){//移动前结点直到count==n
                after = cur;
                cur = cur->next;
            }
            else {
                count++;
            }
            pre = pre->next;

        }
        //cout << count <<endl;

        if (after) {//如果after存在，则跨过cur结点，直接连接cur->next结点
            after->next = cur->next;
        }else if (pre == cur){//pre==cur是只有一个结点且N为1
            return NULL;
        }else {//剩下的情况是链表的长度小于等于n那么直接返回当前结点的下一个结点
            return cur->next;
        }
        delete cur;//释放当前结点
        return head;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {1,2};
    List list(v);
    //list.displayList();
    //cout << "\n";
    Solution so;
    ListNode * head = so.removeNthFromEnd(list.getHead(), 2);
    list.setHead(head);
    list.displayList();
    return 0;
}
