class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        if(s1.size() == 0 || s2.size() == 0)
            return 0;
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};