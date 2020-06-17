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
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *fast = head, *slow = head, *mid = head;
        while(fast && fast->next){
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // split it into two separate list
        mid->next = nullptr;
        ListNode *a = sortList(head), *b = sortList(slow);
        return merge(a, b);
    }
    
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while(a && b){
            if(a->val > b->val){
                cur->next = b;
                b = b->next;
                cur = cur->next;
            }else{
                cur->next = a;
                a = a->next;
                cur = cur->next;
            }
        }
        if(a){
            cur->next = a;
        }
        if(b){
            cur->next = b;
        }
        return dummy->next;
    }
};