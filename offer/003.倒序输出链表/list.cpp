/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        ListNode *p = head;
        int len = 0;
        while(p != nullptr){
            ListNode *next = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = next;
            len++;
        }
        //cout << "len:" << len << endl;
        vector<int> ret(len);
        p = dummy->next;
        int index = 0;
        while(p != nullptr){
            ret[index] = p->val;
            p = p->next;
            index++;
        }
        return ret;
    }
};