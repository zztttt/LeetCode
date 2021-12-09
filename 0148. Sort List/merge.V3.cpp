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
    ListNode* merge(ListNode* a, ListNode* b){
        //cout << a->val << "," << b->val << endl;
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
        ListNode *dummy = new ListNode(0), *p = dummy;
        while(a && b){
            if(a->val > b->val){
                p->next = b;
                b = b->next;
            }else{
                p->next = a;
                a = a->next;
            }
            p = p->next;
        }
        if(a){
            p->next = a;
        }
        if(b){
            p->next = b;
        }
        //cout << dummy->next->val << endl;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        //cout << head->val << endl;
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return head;
        ListNode *fast = head, *slow = head, *tail = head;
        while(fast && fast->next){
            tail = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        // split
        tail->next = nullptr;
        //cout << tail->val << endl;
        //cout << head->val << "," << slow->val << endl;
        return merge(sortList(head), sortList(slow));
        
    }
};