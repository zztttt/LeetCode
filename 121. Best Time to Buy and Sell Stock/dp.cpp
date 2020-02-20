class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) 
            return 0;
        int len = prices.size(), minV = prices[0], ret = 0;
        // record the min number
        vector<int> dp(len, INT_MAX);
        for(int i = 1; i < len; ++i){
            minV = min(minV, prices[i]);
            dp[i] = minV;
        }

        // update result
        for(int i = 1; i < len; ++i){
            if(prices[i] > dp[i])
                ret = max(ret, prices[i] - dp[i]);
        }

        return ret;
    }
};