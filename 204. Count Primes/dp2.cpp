class Solution {
public:
    // number from 1 to n - 1
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        // 1 2 3 4 5...
        //
        
        //isPrime?
        // dp[i] means i is whether a prime
        vector<bool> dp(n, true);
        dp[0] = false;
        dp[1] = false;
        int except = 1;//1 is not a prime
        
        // loop from 2 to n
        for(int i = 2; i * i <= n - 1; ++i){
            if(dp[i]){
                for(int j = i; j * i <= n - 1; ++j){
                    // avoid duplicated count
                    if(dp[j * i]){
                        dp[j * i] = false;
                        except++;
                    }
                }
            }
            
        }
        
        return (n - 1) - except;
    }
};