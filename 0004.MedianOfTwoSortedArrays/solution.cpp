#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

//naive implementation
class Solution {
public:
	stack<int> s;
	double getMid(bool flag) {
		double res = -1;
		if (flag) {
			int a = s.top();
			s.pop();
			int b = s.top();
			res =(double)(a + b) / 2;
		}
		else {
			res = s.top();
		}
		return res;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int all = len1 + len2;
		double mid = all / 2.0;// 5/2=2, select [3] in stack; 4/2 = 2, select ([2]+[3])/2.0
		int pos1 = 0, pos2 = 0, in_stack = 0;
		double res = -1;
		bool flag = all % 2 == 0;
		while (pos1 < len1 && pos2 < len2) {
			if (nums1[pos1] >= nums2[pos2]) {
				//nums2 in stack
				s.push(nums2[pos2]);
				pos2++;
			}
			else {
				//nums1 in s
				s.push(nums1[pos1]);
				pos1++;
			}
			in_stack++;
			//4: in=3 mid=2; 5: in=3, mid=2.5
			if (in_stack > mid) {
				res = getMid(flag);
				return (flag) ? res : (int)res;
			}
		}
		while (pos1 < len1) {
			//nums1 remained
			s.push(nums1[pos1]);
			in_stack++;
			pos1++;
			if (in_stack > mid) {
				res = getMid(flag);
				return (flag) ? res : (int)res;
			}
		}
		while (pos2 < len2) {
			//nums2 remained
			s.push(nums2[pos2]);
			in_stack++;
			pos2++;
			if (in_stack > mid) {
				res = getMid(flag);
				return (flag) ? res : (int)res;
			}
		}
		return (flag) ? res : (int)res;
	}
};

int main() {
	vector<int> a = {};
	vector<int> b = { 2, 4 };
	double res = Solution().findMedianSortedArrays(a, b);
}

