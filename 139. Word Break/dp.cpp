class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int len = s.size();
        if(dict.size() == 0)
            return false;
        
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= len; ++i){
            for(int j = 0; j < i; ++j){
                // s[j:i)
                string tmp = s.substr(j, i - j);
                if(dp[j] && (find(dict.begin(), dict.end(), tmp) != dict.end()))
                    dp[i] = true;
            }
        }
        return dp[len];
    }
};