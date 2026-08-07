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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while (curr) {
            while (curr->next && curr->next->val == val) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;    
    }
};
