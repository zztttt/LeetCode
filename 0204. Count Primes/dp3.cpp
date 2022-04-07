class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> dp = vector<bool>(n, true);
        dp[0] = false;
        dp[1] = false;
        for(int i = 2; i * i <= n - 1; ++i){
            for(int j = i; i * j <= n - 1; ++j){
                dp[i * j] = false;
            }
        }
        
        int ret = 0;
        for(int i = 1; i <= n - 1; ++i){
            if(dp[i] == true){
                ret++;
            }
        }
        return ret;
    }
};