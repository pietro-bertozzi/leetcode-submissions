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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* startA = headA;
        ListNode* startB = headB;
        while (headA != headB) {
            headA = headA ? headA->next : startB;
            headB = headB ? headB->next : startA;
        }
        return headA;
    }
};
