#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

//naive implementation, Runtime: 20 ms, faster than 26.93% of C++ online submissions
class Solution {
public:
	bool isNeg;
	int reverse(int x) {
		//INT_MAX = 2147483647
		string s = to_string(x);
		isNeg = (s[0] == '-') ? true : false;
		if (isNeg)
			s = s.substr(1, s.length() - 1);
		//NOTE:"reverse" has the same name to this class' public function, using std::reverse instead of reverse
		//std::reverse(begin(s), end(s));
		std::reverse(s.begin(), s.end());
		if (s.length() > 10)
			return 0;
		//deal with special number
		if (s.length() == 10) {
			string tmp1 = s.substr(0, 5);
			string tmp2 = s.substr(5, 5);
			int t1 = atoi(tmp1.c_str());
			int t2 = atoi(tmp2.c_str());
			if (t1 > 21474) return 0;
			if (t1 == 21474 && t2 > 83647) return 0;
		}
		//skip '0' in the front area
		int len = s.length();
		while (len-- > 0) {
			if (s[0] == '0')
				s = s.substr(1, s.length() - 1);
			else
				break;
		}
		int r = atoi(s.c_str());
		return isNeg ? -r : r;
	}
};
/*
 * Approach1:Pop and Push Digits & Check before Overflow
 * We can build up the reverse integer one digit at a time. 
 * While doing so, we can check beforehand whether or not appending another digit would cause overflow.
 * pop operation:	push operation:
 * pop = x % 10;	temp = rev * 10 + pop;
 * x = x/10;		rev = temp;
 * Runtime: 16 ms, faster than 50.72% of C++ online submissions for Reverse Integer.
 * Memory Usage: 11.4 MB, less than 0.36% of C++ online submissions for Reverse Integer.
 */
class Solution1 {
public:
	void Pop(int& in, int& t) {
		in = t % 10;
		t = t / 10;
	}
	bool Push(int& res, int push) {
		bool ret = true;
		//rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)
		if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && push > 7))
			||(res < INT_MIN / 10 || (res == INT_MIN / 10 && push < -8))) {
			ret = false;
		}else
			res = res * 10 + push;
		return ret;
	}
	int reverse(int x) {
		int pop, res = 0;
		while (x != 0) {
			Pop(pop, x);
			if (!Push(res, pop)) {
				return 0;
			}
		}
		return res;
	}
};
int main() {
	int a = 321;
	int res = Solution1().reverse(a);
}

