class Solution {
public:
    int ret = INT_MAX;
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        // 0 1 M M M 
        // 0 1 2 M M 
        // 0 1 2 3 M 
        // 0 1 2 3 1 
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};