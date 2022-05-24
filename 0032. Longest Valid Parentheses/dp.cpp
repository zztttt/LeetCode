class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        int len = s.size(), ret = 0;
        vector<int> dp(len, 0);
        if(s[0] == '(' && s[1] == ')'){
            dp[1] = 2;
            ret = 2;
        }
        
        for(int i = 2; i < len; ++i){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = dp[i - 2] + 2;
                } else if(i - dp[i - 1] - 1 >= 0){
                    if(s[i - dp[i - 1] - 1] == '('){
                        dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0)? dp[i - dp[i - 1] - 2]:0);
                    }
                }
            }
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};