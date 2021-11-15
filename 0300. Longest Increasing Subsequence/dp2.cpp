class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int len = v.size(), ret = 0;
        vector<int> dp = vector<int>(len + 1, 1);
        for(int i = 1; i < len + 1; ++i){
            for(int j = 1; j < i; ++j){
                if(v[i - 1] > v[j - 1]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};