#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
string stringToString(string input) {
	if (input.length() < 2) {
		cout << "lenght error" << endl;
		exit(0);
	}
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

/*Brute force
Time Limit Exceeded...
Check all the substring one by one to see if it has no duplicate character.
Using two nested loops with i from 0 to n - 1 and j from i+1 to n, we can enumerate all the substrings of s.
*/
class Solution {
public:
	bool checkUnique(string s) {
		set<char> chars;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (chars.find(s[i]) != chars.end())
				return false;
			chars.insert(s[i]);
		}
		return true;
	}
	int lengthOfLongestSubstring(string s) {
		int len = s.length(), ret = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j <= len ; j++) {
				//string.substr(i,j) len = j 
				string tmp = s.substr(i, j - i);
				ret = checkUnique(tmp) ? max(j - i, ret) : ret;
			}
		}
		return ret;
	}
};

//naive implemention, 480ms, faster than 2.20% submission
class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> m;
		map<char, int>::iterator it;
		int len = s.length(), ret = 0, start = 0, subLen = 0;
		while (start < len) {
			char tmp = s[start];
			it = m.find(tmp);
			if (it == m.end()) {
				m[tmp] = start;
				start++;
				subLen++;
			}
			else {
				start = it->second + 1;
				//save sub len
				ret = max(subLen, ret);
				subLen = 0;
				m.clear();
			}
		}
		ret = max(subLen, ret);
		//subLen = 0;
		return ret;
	}
};

/*

 */
 /* Sliding Window
  * define a mapping of the characters to its index, then we can skip the characters immediately when we found a repeated character.
  * 16ms, faster than 92.99% submission
  * record the last charactor, update the pos and subLen if neccessary
  * Time Complexity = O(n)
  */
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> m;
		map<char, int>::iterator it;
		int ret = 0, start = 0, subLen = 0, len = s.length();
		//record the start of substring and update it if replicating
		for (int i = 0; i < len; i++) {
			char tmp = s[i];
			it = m.find(tmp);
			if (it != m.end() && it->second >= start) {
				//replicate
				start = it->second + 1;
				ret = max(ret, subLen);
				subLen = i - it->second;
			}
			else {
				//not replicate
				subLen++;
			}
			m[tmp] = i;
		}
		ret = max(ret, subLen);
		return ret;
	}
};



int main() {
	string s = "dvdf";
	//s = stringToString(s);
	int ret = Solution2().lengthOfLongestSubstring(s);
	cout << ret << endl;
}