#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

//naive implementation, Runtime: 36 ms, faster than 5.83% of C++ online submissions
//Memory Usage: 766 KB, less than 99.56% of C++ online submissions
class Solution {
public:
	string convert(string s, int numRows) {
		if (s == "")
			return "";
		int perNum = 2 * numRows - 2;
		//deal with one row
		if (perNum == 0)
			return s;
		string res = "";
		//numRows = 4, perNum = 6, col = 3
		int col = numRows - 1;
		int len = s.length();
		int numOfBox = len / perNum + 1;// 5/2+1 = 3
		//loop the rows
		for (int i = 0; i < numRows; i++) {
			//loop boxes
			for (int j = 0; j < numOfBox; j++) {
				//loop cols
				for (int k = 0; k < col; k++) {
					//deal with first char
					if (k == 0) {
						if (j*perNum + i < len)
							res = res + s[j*perNum + i];
					}
					else if (k == numRows - i - 1) {
						if (j*perNum + (perNum - i) < len)
							res = res + s[j*perNum + (perNum - i)];
					}
				}
			}
		}
		return res;
	}
};
int main() {
	string s = "A";
	string res = Solution().convert(s, 1);
}

