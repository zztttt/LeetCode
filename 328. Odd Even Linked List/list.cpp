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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(-1), *dummyTail = dummy, *p = head, *last = p;
        while(p && p->next){
            // pop even node
            ListNode* tmp = p->next;
            last = p;
            p->next = p->next->next;
            p = p->next;
            // insert this node to dummy
            dummyTail->next = tmp;
            dummyTail = tmp;
            tmp->next = nullptr;
        }
        
        // for odd case
        if(last->next)
            last = last->next;
        
        // join the two seperate list
        last->next = dummy->next;
        delete dummy;
        
        return head;
    }
};