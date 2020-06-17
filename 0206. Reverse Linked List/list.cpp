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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* dummy = new ListNode(-1);
        
        // dummy->A->B->......     head->a->b->...
        while(head != nullptr){
            // pop head from original list
            ListNode* tmp = head;
            head = head->next;
            // assign this node to dummy->next
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};