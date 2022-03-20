import java.util.*;

public class Solution {
    public int maxProfit (int[] prices) {
        int len = prices.length;
        int[] dp = new int[len];
        
        int rightMax = prices[len - 1];
        for(int i = len - 2; i >= 0; i--){
            if(prices[i + 1] > rightMax){
                rightMax = prices[i + 1];
            }
            dp[i] = rightMax;
        }
        
        int ret = 0;
        for(int i = 0; i < len - 1; ++i){
            ret = Math.max(ret, dp[i] - prices[i]);
        }
        return ret;
    }
}