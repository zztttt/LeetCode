class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        int len = s.size();
        vector<int> dp(len, 0);
        dp[0] = one(s[0])? 1:0;
        
        for(int i = 1; i < len; ++i){
            string cur = s.substr(i - 1, 2);
            if(!one(s[i]) && !two(cur))
                return 0;
            if(two(cur)){
                if(i == 1)
                    dp[i] = 1;
                else
                    dp[i] += dp[i - 2];
            }
            if(one(s[i]))
                dp[i] += dp[i - 1];
            
        }
        
        return dp[len - 1];
    }
    
    bool two(string s){
        char c1 = s[0], c2 = s[1];
       return (c1 == '2' && c2 >= '0' && c2 <= '6')
            ||(c1 == '1');
    }
    bool one(char c){
        return c > '0' && c <= '9';
    }
};