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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *pa = a, *pb = b, *start;
        while(pa && pb){
            pa = pa->next;
            pb = pb->next;
        }
        if(!pb){
            while(pa){
                pa = pa->next;
                a = a->next;
            }
        }else if(!pa){
            while(pb){
                pb = pb->next;   
                b = b->next;
            }
        }
        while(a && b){
            if(a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
    
    
    ListNode* getIntersectionNode_hash(ListNode *a, ListNode *b){
        if(a == nullptr || b == nullptr)
            return nullptr;
       set<ListNode*> st;
        while(a){
            st.insert(a);
            a = a->next;
        }
        while(b){
            if(st.find(b) != st.end())
                return b;
            b = b->next;
        }
        return nullptr;   
    }
};