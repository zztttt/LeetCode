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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(-1), *p = head, *tail = nullptr;
        // count length
        int len = 0;
        while(p){
            p = p->next;
            len++;
        }
        k = k % len;
        if(k == 0) 
            return head;
        // find tail
        p = head;
        for(int i = 0; i < len - k - 1; ++i){
            p = p->next;
        }
        // split it into two lists
        ListNode* rest = p->next;
        p->next = nullptr;
        // merge
        dummy->next = rest;
        while(rest->next){
            rest = rest->next;
        }
        rest->next = head;

        return dummy->next;
    }
};