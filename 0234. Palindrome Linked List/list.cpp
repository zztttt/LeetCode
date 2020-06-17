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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        
        // find the middle node
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
    
        // reverse the back list
        ListNode* reverse = reverseList(slow);
        //slow->next = nullptr;
        
        // compare one by one
        while(reverse && head){
            if(reverse->val != head->val)
                return false;
            reverse = reverse->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode *dummy = new ListNode(-1);
        
        while(head){
            // pop first node from head
            ListNode* tmp = head;
            head = head->next;
            // insert the node at dummy->next
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};