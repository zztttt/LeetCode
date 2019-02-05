#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

//naive implementation. Brute force. Runtime: 2444 ms, faster than 3.20% of C++ online submission
//Memory Usage: 766 KB, less than 96.69% of C++ online submissions
class Solution {
public:
	bool checkPalindromic(string s) {
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[i] != s[len - i - 1])
				return false;
		}
		return true;
	}
	string longestPalindrome(string s) {
		int len = s.length(), max = 0;
		string res;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len + 1; j++) {
				string tmp = s.substr(i, j - i);
				if (checkPalindromic(tmp)) {
					if (tmp.length() > max) {
						max = tmp.length();
						res = tmp;
					}
				}
			}
		}
		return res;
	}
};

/*
 * approach1:dynamic programming
 * dynamic equation: P(i, j) = true(palindrome) false(otherwise)
 * therefore P(i, j) = ( P(i+1, j-1) and Si==Sj )
 * base cases: P(i, i) = true, P(i, i+1) = (Si == Si+1)
 * 
 */
//NOT FINISHED YET !!!!!
class Solution1 {
public:
	int len;
	void show(int** state) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cout << state[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	bool checkRange(int i, int j) {
		return (j + 1 < len) && (i - 1 >= 0);
	}
	string longestPalindrome(string s) {
		len = s.length();
		string res;
		//int s[len][len];
		int** state = new int*[len];
		for (int i = 0; i < len; i++) {
			state[i] = new int[len];
			//state[i][i] = 1;
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j)
					state[i][j] = 1;
				else if (j == i + 1)
					state[i][j] = s[i] == s[i + 1];
				else
					state[i][j] = 9;
			}
		}
		show(state);
		//P(i, j) = (P(i - 1, j + 1) and Si == Sj)
		for (int i = 0; i < len; i++) {
			for (int j = i+1; j < len; j++) {
				if (checkRange(i, j)) {
					state[i][j] = state[i - 1][j + 1] && (s[i] == s[j]);
					show(state);
				}
			}
		}
		show(state);
		return res;
	}
};
int main() {
	string s = "babad";
	string res = Solution1().longestPalindrome(s);
}

