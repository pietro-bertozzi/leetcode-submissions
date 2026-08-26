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
    bool isPalindrome(ListNode* head) {
        ListNode* l = head;
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* curr = s;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* r = prev;
        while (r) {
            if (l->val != r->val) {
                return false;
            }
            l = l->next;
            r = r->next;
        }
        return true;
    }
};
