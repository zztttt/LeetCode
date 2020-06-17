#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;

//naive implementation
//Runtime: 4 ms faster then 100%
//Memory Usage : 8.9 MB better then 25.5%
class Solution {
public:
	vector<string> trans(char c) {
		vector<string> ret;
		switch (c) {
		case '2':ret = { "a", "b", "c" }; break;
		case '3':ret = { "d", "e", "f" }; break;
		case '4':ret = { "g", "h", "i" }; break;
		case '5':ret = { "j", "k", "l" }; break;
		case '6':ret = { "m", "n", "o" }; break;
		case '7':ret = { "p", "q", "r", "s" }; break;
		case '8':ret = { "t", "u", "v" }; break;
		case '9':ret = { "w", "x", "y", "z" }; break;
		default:break;
		}
		return ret;
	}
	vector<string> compute(vector<vector<string>> cluster) {
		//init default ret
		int clusterLen = cluster.size();
		vector<string> ret = cluster[0];
		cluster.erase(cluster.begin());

		//loop every vector
		for (auto j : cluster) {
			//judge whether this vector finished
			int beforeNum = ret[0].length();
			while (ret[0].length() == beforeNum) {
				//pop the first substance
				string tmp = ret.front();
				ret.erase(ret.begin());
				//store new string in vector
				for (auto p : j) {
					ret.push_back(tmp + p);
				}
			}
		}
		return ret;
	}
	vector<string> letterCombinations(string d) {
		int len = d.length();
		vector<string> ret = {};

		if (d.empty())return ret;
		if (len == 1)return trans(d[0]);
		
		//store existing set
		vector<vector<string>> cluster;
		for (int i = 0; i < len; ++i) {
			cluster.push_back(trans(d[i]));
		}
		ret = compute(cluster);
		return ret;
	}
};

int main() {
	string d = "234";
	vector<string> res = Solution().letterCombinations(d);

	system("pause");
}