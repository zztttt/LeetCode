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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode *last = dummy, *cur = head;
        for(int i = 0; i < left - 1; ++i){
            last = cur;
            cur = cur->next;
        }
        int offset = right - left;
        ListNode* start = cur;
        while(offset > 0){
            last->next = start->next;
            ListNode* p = last;
            for(int i = 0; i < offset; ++i){
                p = p->next;
            }
            start->next = p->next;
            p->next = start;
            offset--;
            start = last->next;
        }
        return dummy->next;
    }
};