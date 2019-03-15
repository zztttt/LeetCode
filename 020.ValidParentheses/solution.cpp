#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

//naive implementation
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage : 8.8 MB, less than 94.11% of C++ online submissions for Valid Parentheses.
class Solution {
public:
	stack<char> Stack;
	bool isMatch(char a, char b) {
		bool ret;
		switch (a) {
		case '(':ret = (b == ')'); break;
		case '[':ret = (b == ']'); break;
		case '{':ret = (b == '}'); break;
		default:ret = false;
		}
		return ret;
	}
	bool isValid(string s) {
		int len = s.length();
		if (len == 0)return true;
		Stack.push(s[0]);
		for (int i = 1; i < len; ++i) {
			if (Stack.empty()) {
				Stack.push(s[i]);
			}
			else {
				char tmp = Stack.top();
				//match
				if (isMatch(tmp, s[i])) {
					Stack.pop();
				}
				else {
					Stack.push(s[i]);
				}
			}
		}
		return Stack.empty();
	}
};

int main() {
	string s = "()[]{}";
	bool ret = Solution().isValid(s);
	system("pause");
}