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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr) return l1;
        int carry = 0;
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        while(l1 && l2){
            int cur = l1->val + l2->val + carry;
            carry = cur / 10;
            cur = cur % 10;

            tail->next = new ListNode(cur);
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* l3 = nullptr;
        if(l1) l3 = l1;
        if(l2) l3 = l2;
        while(l3){
            int cur = l3->val + carry;
            carry = cur / 10;
            cur = cur % 10;

            tail->next = new ListNode(cur);
            tail = tail->next;
            l3 = l3->next;
        }

        if(carry == 1){
            tail->next = new ListNode(1);
            tail = tail->next;
        }

        return dummy->next;
    }
};