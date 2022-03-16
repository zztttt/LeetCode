import java.util.*;

public class Solution {
    public int[] FindGreatestSumOfSubArray (int[] v) {
        if(v.length == 0)
            return null;
        int len = v.length, ret = v[0], left = 0, right = 0, retLeft = 0, retRight = 0;
        int[] dp = new int[len];
        dp[0] = v[0];
        for(int i = 1; i < len; ++i){
            right++;
            if(dp[i - 1] + v[i] < v[i]){
                left = i;
                dp[i] = v[i];
            }else{
                dp[i] = dp[i - 1] + v[i];
            }
            
            if(dp[i] > ret || (dp[i] == ret && (right - left) > (retRight - retLeft))){
                ret = dp[i];
                retLeft = left;
                retRight = right;
            }
        }
        
        return Arrays.copyOfRange(v, retLeft, retRight + 1);
    }
}