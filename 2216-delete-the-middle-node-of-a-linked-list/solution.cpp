/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode* s = head;
        ListNode* f = s->next->next;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* toDelete = s->next;
        s->next = s->next->next;
        delete toDelete;
        return head;
    }
};
