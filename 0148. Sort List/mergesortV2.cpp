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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        // iterator ends
        if(head->next == nullptr)
            return head;
        ListNode *fast = head, *slow = head, *mid = slow;
        while(fast && fast->next){
            mid = slow;

            fast = fast->next->next;
            slow = slow->next;
        }
        // split it into two lists
        mid->next = nullptr;
        //
        ListNode* ret = merge(sortList(head), sortList(slow));

        return ret;
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode *dummy = new ListNode(-1), *tail = dummy;

        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        ListNode* rest = nullptr;
        if(a) rest = a;
        if(b) rest = b;
        while(rest){
            tail->next = rest;
            tail = tail->next;
            rest = rest->next;
        }

        return dummy->next;
    }
};