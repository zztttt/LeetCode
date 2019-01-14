#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
	  ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  static ListNode* l1 = NULL;
  static ListNode* l2 = NULL;

//naive implemention, faster than 95.93% submissions
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//2-4-3, 5-6-4
		//init ret list
		ListNode* dummyHead = new ListNode(-1);
		ListNode* tail = dummyHead;
		bool carry = false;
		//both not empty
		while (l1 && l2) {
			int t = l1->val + l2->val;
			if (carry) {
				t = t + 1;
				carry = false;
			}
			if (t > 9) {
				carry = true;
				t = t % 10;
			}
			ListNode* tmp = new ListNode(t);
			//add tmp to tail
			tail->next = tmp;
			//tmp becomes new tail
			tail = tmp;

			l1 = l1->next; l2 = l2->next;
		}

		//deal with left node
		while (l1) {
			int t = l1->val;
			if (carry) {
				t++;
				carry = false;
			}
			if (t > 9) {
				t = t % 10;
				carry = true;
			}
			tail->next = new ListNode(t);
			tail = tail->next;
			l1 = l1->next;
		}
		while (l2) {
			int t = l2->val;
			if (carry) {
				t++;
				carry = false;
			}
			if (t > 9) {
				t = t % 10;
				carry = true;
			}
			tail->next = new ListNode(t);
			tail = tail->next;
			l2 = l2->next;
		}
		if (carry) {
			tail->next = new ListNode(1);
			carry = false;
			tail = tail->next;
		}
		//skip dummyHead
		return dummyHead->next;

	}
};

void init() {
	//init l1: 2-4-3
	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	//init l2: 5-6-4
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
}

int main() {
	init();
	ListNode* ret = Solution().addTwoNumbers(l1, l2);
}