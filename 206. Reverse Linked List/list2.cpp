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
            return nullptr;
        ListNode *dummy = new ListNode(-1);
        while(head){
            // pop
            ListNode *tmp = head;
            head = head->next;
            // insert  at dummy->next
            tmp->next = dummy->next;
            dummy->next = tmp;
        }

        return dummy->next;
    }
};