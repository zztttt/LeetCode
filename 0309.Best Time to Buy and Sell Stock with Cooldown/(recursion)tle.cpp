class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        return dfs(prices, 0, true);
    }
    int dfs(const vector<int>& prices, int day, bool buy){
        if(day >= prices.size()){
            return 0;
        }
        
        // First Choice
        int ans1 = dfs(prices, day + 1, buy); // no transaction this day
        
        
        // Second Choice
        int ans2 = 0;
        // doing the required transaction this day
        if(buy){
            ans2 = -prices[day] + dfs(prices, day + 1, false);
        }else{
            ans2 = prices[day] + dfs(prices, day + 2, true);
        }
        
        return max(ans1, ans2);
    }
};