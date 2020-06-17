class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || amount == 0)
            return 0;
        int len = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // init first element
        sort(coins.begin(), coins.end());
        if(coins[0] > amount)
            return -1;
        else
            dp[coins[0]] = 1;
        // process dp
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < len && coins[j] <= i; ++j){
                int preAmount = i - coins[j];
                if(dp[preAmount] != INT_MAX){
                    dp[i] = min(dp[i], dp[preAmount] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX? -1:dp[amount];
    }
};
// 0 1 M M
// 