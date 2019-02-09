#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

//naive implementation, Runtime: 20 ms, faster than 100.00% of C++ online submissions for String to Integer (atoi).
//Memory Usage : 12.2 MB, less than 0.57% of C++ online submissions for String to Integer(atoi).
class Solution {
public:
	bool isNeg = false;
	bool checkStart(char c) {
		return (c >= '0' && c <= '9') || c == '-' || c == '+';
	}
	bool checkNum(char c) {
		return (c >= '0' && c <= '9');
	}
	int stringToInt(string str) {
		string s = str;
		if (s[0] == '-' || s[0] == '+') { 
			isNeg = s[0] == '-' ? true : false;
			s = s.substr(1, s.length() - 1); 
		}
		//not valid
		if (s.length() == 0)return 0;
		if (s[0] < '0' || s[0] > '9') return 0;
		//skip the first '0's
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[0] != '0')
				break;
			s = s.substr(1, s.length() - 1);
		}
		if (s.length() > 10)
			return isNeg ? INT_MIN : INT_MAX;
		//deal with special number
		if (s.length() == 10) {
			int tmp1 = atoi(s.substr(0, 5).c_str());
			int tmp2 = atoi(s.substr(5, 5).c_str());
			if (isNeg) {
				//check negtive num overflow
				if (tmp1 > 21474 || (tmp1 == 21474 && tmp2 >= 83648))return INT_MIN;
			}
			else {
				//check positive num overflow
				if (tmp1 > 21474 || (tmp1 == 21474 && tmp2 >= 83647))return INT_MAX;
			}
		}
		//general case
		int res = atoi(s.c_str());
		return isNeg ? -res : res;
	}
	int myAtoi(string s) {
		int len = s.length();
		int start = 0, end = 0, res;
		//find start and check the first char
		for (int i = 0; i < len; i++) {
			if (s[i] != ' ') {
				start = i; 
				if (!checkStart(s[start]))
					return 0;
				break;
			}
		}
		for (int i = start + 1; i < len; i++) {
			//check valid or arrive the tail
			if (!checkNum(s[i])) {
				end = i - 1;
				break;
			}
			else if (i == len - 1) {
				end = i;
			}
		}
		res = stringToInt(s.substr(start, end - start + 1));
		return res;
	}
};

//NO SOLUTION FOR THIS QUESTION
int main() {
	string s = "+5+";
	int res = Solution().myAtoi(s);
	system("pause");
}

