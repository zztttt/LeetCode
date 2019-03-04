#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//naive implemantation,faster then 25.63%,  T = O(n^2)
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxSize = 0, len = height.size();
		for (int i = 0; i < len-1; i++) {
			for (int j = i+1; j < len; j++) {
				int tmp = min(height[i], height[j])*(j-i);
				maxSize = tmp > maxSize ? tmp : maxSize;
			}
		}
		return maxSize;
	}
};

/*
* Runtime: 20 ms, faster than 98.54% of C++ online submissions for Container With Most Water.
* Memory Usage: 10.2 MB, less than 11.13% of C++ online submissions for Container With Most Water.
*/
class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size(), start = 0, end = len - 1, maxSize = 0;
		while (start < end) {
			int tmp = min(height[start], height[end])*(end - start);
			maxSize = tmp > maxSize ? tmp : maxSize;
			if (height[start] > height[end])
				end--;
			else start++;
		}
		return maxSize;
	}
};
int main() {
	vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	int res = Solution2().maxArea(v);
	system("pause");
}