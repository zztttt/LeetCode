class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i < len2 + 1; ++i){
            // if(p[i - 1] == '*'){
            //     dp[0][i] = dp[0][i - 1];
            // }else{
            //     break;
            // }
            if(p[i - 1] == '*' && dp[0][i - 2])
                dp[0][i] = true;
        }
        
        for(int i = 1; i < len1 + 1; ++i){
            for(int j = 1; j < len2 + 1; ++j){
                if(p[j - 1] == s[i - 1] || p[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j - 1] == '*'){
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.'){
                        dp[i][j] = dp[i][j - 2];
                    }else{
                        dp[i][j] = (dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]);
                    }
                }
            }
        }
        
        return dp[len1][len2];
    }
};