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

//naive implementation, Runtime: 35 ms, faster than 95.93% of C++ online submissions for Add Two Numbers.
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

/*
Approach 1: Elementary Math
Runtime: 32 ms, faster than 96.89% of C++ online submissions for Add Two Numbers
The pseudocode is as following:
Initialize current node to dummy head of the returning list.
Initialize carry to 0.
Initialize pp and qq to head of l1l1 and l2l2 respectively.
Loop through lists l1l1 and l2l2 until you reach both ends.
Set xx to node pp's value. If pp has reached the end of l1l1, set to 00.
Set yy to node qq's value. If qq has reached the end of l2l2, set to 00.
Set sum = x + y + carrysum=x+y+carry.
Update carry = sum / 10carry=sum/10.
Create a new node with the digit value of (sum \bmod 10)(summod10) and set it to current node's next, then advance current node to next.
Advance both pp and qq.
Check if carry = 1carry=1, if so append a new node with digit 11 to the returning list.
Return dummy head's next node.
 */
class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//init ret list
		ListNode* dummyHead = new ListNode(-1);
		ListNode* tail = dummyHead;
		int carry = 0;
		//not both empty
		while(l1 || l2){
			int t1 = (l1) ? l1->val : 0;
			int t2 = (l2) ? l2->val : 0;
			int t = carry + t1 + t2;
			carry = 0;
			if(t > 9){
				carry = 1;
				t = t % 10;
			}
			tail->next = new ListNode(t);
			tail = tail->next;
			if (l1)l1 = l1->next;
			if (l2)l2 = l2->next;
		}
		if (carry) {
			tail->next = new ListNode(1);
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
	ListNode* ret = Solution2().addTwoNumbers(l1, l2);
}