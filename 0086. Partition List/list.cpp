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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(-1), *greater = new ListNode(-1);
        ListNode *p1 = less, *p2 = greater;
        while(head){
            if(head->val < x){
                p1->next = head;
                head = head->next;
                p1->next->next = nullptr;
                p1 = p1->next;
            }else if(head->val >= x){
                p2->next = head;
                head = head->next;
                p2->next->next = nullptr;
                p2 = p2->next;
            }
        }
        
        p1->next = greater->next;
        return less->next;
    }
};