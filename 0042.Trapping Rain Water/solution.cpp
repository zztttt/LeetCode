#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>

using namespace std;
//Runtime: 8 ms, faster than 99.26% of C++ online submissions for Trapping Rain Water.
//Memory Usage : 9.1 MB, less than 99.45% of C++ online submissions for Trapping Rain Water
class Solution {
public:
	int trap(vector<int>& height) {
		//0,1,0,2,1,0,1,3,2,1,2,1
		int len = height.size();
		int leftMax = 0, rightMax = 0, ret = 0;
		vector<int> dp(len, 0);
		//store max number in the left area of dp[i]
		for (int i = 0; i < len; ++i) {
			dp[i] = leftMax;
			leftMax = max(height[i], leftMax);
		}
		//find the min number in the right area of do[i], indicating wheather can store water
		for (int i = len - 1; i >= 0; --i) {
			//dp[i] imply that wheather it can store water
			dp[i] = min(dp[i], rightMax);
			rightMax = max(height[i], rightMax);
		}
		//add all dp[i]-height[i]
		for (int i = 0; i < len; ++i) {
			if(dp[i] > height[i])
				ret = ret + dp[i] - height[i];
		}
		return ret;
	}
};
int main() {
	vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ret = Solution().trap(input);
	system("pause");
}