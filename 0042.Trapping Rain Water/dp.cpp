class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int len = height.size(), left = INT_MIN, right = INT_MIN, ret = 0;
        vector<int> dp(len, INT_MIN);
        
        // record leftMax
        for(int i = 1; i < len; ++i){
            left = max(height[i - 1], left);
            dp[i] = left;
            //cout << dp[i] << ", ";
        }
        // record rightMax
        for(int i = len - 2; i >= 0; --i){
            right = max(height[i + 1], right);
            dp[i] = min(dp[i], right);
        }
        
        for(int i = 1; i < len - 1; ++i){
            if(dp[i] > height[i]){
                ret += dp[i] - height[i];
            }
        }
        
        
        return ret;
    }
};