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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a && b){
            a = a->next;
            b = b->next;
        }
        // a.len < b.len
        if(!a && b){
            a = headB;
            while(a && b){
                a = a->next;
                b = b->next;
            }
            b = headA;
        }else if(a && !b){
            // a.len > b.len
            b = headA;
            while(a && b){
                a = a->next;
                b = b->next;
            }
            a = headB;
        }else{
            // a.len == b.len
            a = headA;
            b = headB;
        }

        while(a && b){
            if(a == b)
                return a;
            a = a->next;
            b = b->next;
        }

        return nullptr;
    }
};