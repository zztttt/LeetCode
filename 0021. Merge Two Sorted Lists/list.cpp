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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* dummy = new ListNode(-1), *tail = dummy;
        while(l1 && l2){
            int a = l1->val, b = l2->val;
            if(a > b){
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }else{
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
        }

        ListNode* rest = nullptr;
        if(l1) rest = l1;
        if(l2) rest = l2;
        while(rest){
            tail->next = rest;
            tail = tail->next;
            rest = rest->next;
        }

        return dummy->next;
    }
};