class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), start = 0, ret = INT_MIN;
        // dp[i]
        vector<int> dp(len, 1);
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < i; ++j){
                if(v[i] > v[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};