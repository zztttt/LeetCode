class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() < 0 || amount <= 0)
            return 0;
        int len = coins.size();
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount + 1, INT_MAX);
        if(amount < coins[0])
            return -1;
        dp[0] = 0;
        dp[coins[0]] = 1;
        
        for(int i = coins[0]; i <= amount; ++i){
            for(int j = 0; j < len; ++j){
                int pre = i - coins[j];
                //cout << "pre:" << pre << endl;
                if(pre >= 0 && dp[pre] != INT_MAX){
                    dp[i] = min(dp[i], dp[pre] + 1);
                }
            }
            //show(dp);
            
        }
        
        return dp[amount] == INT_MAX?-1:dp[amount];
    }
    void show(vector<int> v){
        for(int i : v){
            cout << i << ",";
        }
        cout << endl;
    }
};