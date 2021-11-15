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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *last = nullptr;
        while(p){
            if(p->val == val){
                if(p == head){
                    // head
                    head = head->next;
                }else if(p->next == nullptr){
                    // tail
                    last->next = nullptr;
                }else{
                    last->next = p->next;
                }
            }else{
                last = p;
            }
            p = p->next;
        }
        return head;
    }
};