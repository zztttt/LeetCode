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
        //dummy head
        ListNode* p = new ListNode(0);
        ListNode* ret = p;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }else{
                p->next = l1;
                l1 = l1->next;
            }
            p =p->next;
        }
        ListNode* l3 = nullptr;
        if(l1)
            l3 = l1;
        else
            l3 = l2;
        while(l3){
            p->next = l3;
            p = p->next;
            l3 = l3->next;
        }
        return ret->next;
    }
};