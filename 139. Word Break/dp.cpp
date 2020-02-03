class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int len = s.size();
        if(dict.size() == 0)
            return false;
        
        bool dp[len + 1];
        for(int i = 0; i < len; ++i){
            dp[i + 1] = false;
        }
        dp[0] = true;
        
        for(int i = 1; i <= len; ++i){
            for(int j = 0; j < i; ++j){
                string tmp = s.substr(j, i - j);
                if(dp[j] && (find(dict.begin(), dict.end(), tmp) != dict.end()))
                    dp[i] = true;
            }
        }
        return dp[len];
    }
};