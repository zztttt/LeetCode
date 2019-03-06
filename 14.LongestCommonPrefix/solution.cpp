#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//naive implementation
//Runtime: 8 ms, faster than 99.70% of C++ online submissions for Longest Common Prefix.
//Memory Usage : 9.5 MB, less than 60.88% of C++ online submissions for Longest Common Prefix.
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";
		if (strs.size() == 1)return strs[0];
		int pos = 0, vLen = strs.size(), minStrLen = strs[0].length();
		bool stop = false;
		for (int i = 1; i < vLen; i++) {
			minStrLen = min(minStrLen, (int)strs[i].length());
		}
		while (pos < minStrLen && !stop) {
			char tmp = strs[0][pos];
			for (int i = 1; i < vLen; i++) {
				if (tmp != strs[i][pos]) {
					stop = true;
					break;
				}
			}
			pos++;
		}
		return stop ? strs[0].substr(0, pos - 1) : strs[0].substr(0, minStrLen);
	}
};
/*
* Divide and Conquer:     分而治之
* LCP(S1,..SN) = LCP(LCP(S1,...SK), LCP(SK+1, ...SN))
* Runtime: 8 ms, faster than 99.47% of C++ online submissions for Longest Common Prefix.
* Memory Usage: 12.6 MB, less than 10.97% of C++ online submissions for Longest Common Prefix.
*/
class Solution2 {
public:
	string getPairCommon(string left, string right) {
		int lLen = left.length(), rLen = right.length();
		for (int i = 0; i < lLen; i++) {
			if (i == rLen - 1)return (right[i] == left[i]) ? right : right.substr(0, rLen - 1);
			if (left[i] != right[i])return left.substr(0, i);
		}
		return left;
	}
	string LCP(vector<string>& strs, int start, int end) {
		if (start == end) {
			return strs[start];
		}
		else {
			int mid = (start + end) / 2;//0 1 2 3， （0+3）/2 = 1
			string left = LCP(strs, start, mid);
			string right = LCP(strs, mid + 1, end);
			return getPairCommon(left, right);
		}
	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";
		if (strs.size() == 1)return strs[0];
		return LCP(strs, 0, strs.size() - 1);
	}
};
int main() {
	vector<string> v = { "dog","racecar","car" };
	string res = Solution2().longestCommonPrefix(v);
	system("pause");
}