#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
static ListNode* l1 = NULL;
static ListNode* l2 = NULL;

//naive implementation
//Runtime: 8 ms, faster than 99.86% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage : 9.7 MB, less than 62.60% of C++ online submissions for Remove Nth Node From End of List.
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int listLen = 0, pos = 0;
		ListNode* ret = head;
		bool found = false;
		while (head != NULL) {
			++listLen;
			head = head->next;
		}
		if (listLen == n) {
			return ret->next;
		}
		//retore head
		head = ret;
		while (pos++ != listLen - n - 1) {
			head = head->next;
		}
		//skip the node
		head->next = head->next->next;
		
		return ret;
	}
};

/** Approach 1: Two pass algorithm
* We notice that the problem could be simply reduced to another one : Remove the (L - n + 1)(L−n+1) th node from the beginning in the list , 
* where LL is the list length. This problem is easy to solve once we found list length LL.
* Runtime: 12 ms, faster than 27.62% of C++ online submissions for Remove Nth Node From End of List.
* Memory Usage: 9.7 MB, less than 33.61% of C++ online submissions for Remove Nth Node From End of List.
*/
class Solution2 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//create a dummy node to deal with corner case
		ListNode* dummy = new ListNode(0);
		ListNode* first = head;
		int len = 0;
		dummy->next = head;

		while (first != NULL) {
			++len;
			first = first->next;
		}
		len = len - n;
		first = dummy;
		while (len > 0) {
			--len;
			first = first->next;
		}
		first->next = first->next->next;
		return dummy->next;
	}
};

void init() {
	//init l1: 2-4-3
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);
	//init l2: 5-6-4
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
}

int main() {
	init();
	ListNode* res = Solution2().removeNthFromEnd(l1, 2);

	system("pause");
}