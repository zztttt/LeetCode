class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        // isPrime?
        vector<bool> dp(n, true);
        dp[0] = false;dp[1] = false;
        int ret = n - 2;
        
        for(int i = 0; i * i < n; ++i){
            if(dp[i]){
                for(int j = i; j * i < n; ++j){
                    if(dp[j * i]){ // i is a prime
                        dp[j * i] = false;
                        ret--;
                    }
                }
            }
        }
        return ret;
    }
};