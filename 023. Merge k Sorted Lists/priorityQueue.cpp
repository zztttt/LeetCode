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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, less> q;
        for(ListNode* l: lists){
            if(l)
                q.push(l);
        }

        ListNode *dummy = new ListNode(-1), *tail = dummy;
        while(!q.empty()){
            ListNode* p = q.top();
            q.pop();
            // insert it at tail
            tail->next = p;
            tail = tail->next;
            // update p, if not null, push it into queue
            p = p->next;
            if(p != nullptr){
                q.push(p);
            }
        }
        return dummy->next;
    }

    class less{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
};