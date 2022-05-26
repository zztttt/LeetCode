class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto comparator = [&](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0]? a[1] < b[1] : a[0] < b[0];
        };
        
        sort(envelopes.begin(), envelopes.end(), comparator);
        
        // longest increasing subsequence
        int len = envelopes.size(), ret = 1;
        vector<int> dp(len, 1);
        
        // dp[i] -> max subsequece in s[j, i)
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < i; ++j){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            //ret = max(ret, dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};