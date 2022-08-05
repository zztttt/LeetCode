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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *last = new ListNode(-1, head), *ret = last;
        for(int i = 0; i < n; ++i){
            slow = slow-> next;
        }

        while(fast && slow){
            last = fast;
            fast = fast->next;
            slow = slow->next;
        }

        last->next = last->next->next;
        return ret->next;
    }
};