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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* s = head;
        ListNode* f = s->next;
        while (f && f->next && s != f) {
            s = s->next;
            f = f->next->next;
        }
        return s == f;
    }
};
