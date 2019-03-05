#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//naive implementation,
//Runtime: 48 ms, faster than 97.18% of C++ online submissions for Roman to Integer.
//Memory Usage : 30.8 MB, less than 95.64% of C++ online submissions for Roman to Integer.
class Solution {
public:
	int tranChar(char c) {
		int ret;
		switch (c){
			case 'I': ret = 1; break;
			case 'V': ret = 5; break;
			case 'X': ret = 10; break;
			case 'L': ret = 50; break;
			case 'C': ret = 100; break;
			case 'D': ret = 500; break;
			case 'M': ret = 1000; break;	
		default:
			ret = -1;
			break;
		}
		return ret;
	}
	int romanToInt(string s) {
		int len = s.length(), ret = 0;
		//leave the last one alone
		for (int i = 0; i < len - 1; i++) {
			int tmp = tranChar(s[i]);
			int next = tranChar(s[i + 1]);
			if (tmp < next)
				ret = ret - tmp;
			else
				ret = ret + tmp;
		}
		ret = ret + tranChar(s[len - 1]);
		return ret;
	}
};

int main() {
	string s = "CDXLIX";
	int res = Solution().romanToInt(s);
	system("pause");
}