class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while(head != nullptr){
            ListNode *p = head, *old = dummy->next;
            head = head->next;
            
            p->next = old;
            dummy->next = p;
        }
        head = dummy->next;
        vector<int> ret;
        while(head != nullptr){
            ret.push_back(head->val);
            head = head->next;
        }
        return ret;
    }
};