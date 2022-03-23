import java.util.*;


public class Solution {
    public int solve (String nums) {
        if(nums.length() == 0 || nums.charAt(0) == '0')
            return 0;
        if(nums.length() == 1)
            return 1;
        char[] s = nums.toCharArray();
        int len = s.length;
        int[] dp = new int[len];
        dp[0] = 1;
        if((s[0] == '1' && s[1] >= '1') || (s[0] == '2' && s[1] >= '1' && s[1] <= '6')){
            dp[1] = 2;
        }else{
            dp[1] = 1;
        }
        
//         for(int i: dp){
//             System.out.println(i);
//         }
        
        for(int i = 2; i < len; ++i){
            char cur = s[i], pre = s[i - 1];
            int num = (s[i - 1] - '0') * 10 + s[i] - '0';
            
            if(s[i] >= '1'){
                dp[i] = dp[i - 1];
            }
            if(num >= 10 && num <= 26){
//                 if(i == 1)
//                     dp[i] += 1;
//                 else
                    dp[i] = dp[i] + dp[i - 2];
            }
        }
        return dp[len - 1];
    }
}