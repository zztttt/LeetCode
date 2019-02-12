#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <iostream>
using namespace std;


//naive implementation, Runtime: 144 ms, faster than 45.36% of C++ online submissions for Palindrome Number.
//Memory Usage : 84.6 MB, less than 0.63% of C++ online submissions for Palindrome Number.
class Solution {
public:
	bool isPalindrome(int a) {
		if (a < 0)return false;
		int s = a, pop, res = 0;
		while (s != 0) {
			pop = s % 10;
			s = s / 10;
			if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)))
				return false;
			res = res * 10 + pop;
		}
		return res == a ? true : false;
	}
};
/*
* Runtime: 136 ms, faster than 88.05% of C++ online submissions for Palindrome Number.
* Memory Usage: 72.9 MB, less than 0.63% of C++ online submissions for Palindrome Number. 
*/
class Solution1 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))return false;
		int reversed = 0;
		//reverse half of int x, until reversed <= x
		//12321 -> x = 12, reversed = 123; 1221 -> x = 12, reversed = 12
		//10 -> x = 10, reversed = 0 -> x = 1, reversed = 0 -> x = 0, reversd = 1
		while (x > reversed) {
			reversed = reversed * 10 + x % 10;
			x = x / 10;
		}
		return x == reversed || x == reversed / 10;
	}
};
int main() {
	int a = 10;
	bool res = Solution1().isPalindrome(a);
	system("pause");
}

