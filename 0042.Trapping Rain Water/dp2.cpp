class Solution {
public:
    int trap(vector<int>& h) {
        int len = h.size();
        vector<int> dp(len, 0);
        
        int leftMax = 0;
        for(int i = 1; i < len; ++i){
            leftMax = max(leftMax, h[i - 1]);
            dp[i] = leftMax;
        }
        
        int rightMax = 0;
        for(int i = len - 2; i >= 0; --i){
            rightMax = max(rightMax, h[i + 1]);
            dp[i] = min(dp[i], rightMax);
        }
        
        int ret = 0;
        for(int i = 1; i < len - 1; ++i){
            cout << dp[i] << ",";
            if(dp[i] > h[i])
                ret += (dp[i] - h[i]);
        }
        return ret;
    }
};