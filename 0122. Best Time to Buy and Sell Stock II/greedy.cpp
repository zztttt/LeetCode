class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int len = prices.size(), ret = 0, last = prices[0];
        for(int i = 1; i < len; ++i){
            if(prices[i] > last){
                ret = ret + prices[i] - last;
            }
            last = prices[i];
        }

        return ret;
    }
};