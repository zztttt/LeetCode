public class Solution {
    public int FindGreatestSumOfSubArray(int[] v) {
        if(v.length == 0)
            return 0;
        int len = v.length, ret = v[0];
        int[] dp = new int[len];
        dp[0] = v[0];
        for(int i = 1; i < len; ++i){
            dp[i] = Math.max(v[i], dp[i - 1] + v[i]);
            ret = Math.max(ret, dp[i]);
        }
        return ret;
    }
}