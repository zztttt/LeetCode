import java.util.*;


public class Solution {
    public boolean match (String ss, String pp) {
        int len1 = ss.length(), len2 = pp.length();
        char[] s = ss.toCharArray();
        char[] p = pp.toCharArray();
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        for(int i = 0; i < len1 + 1; ++i){
            for(int j = 0; j < len2 + 1; ++j){
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        for(int i = 0; i < len1 + 1; ++i){
            for(int j = 1; j < len2 + 1; ++j){
                if(p[j - 1] != '*'){
                    if(i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                        dp[i][j] = dp[i - 1][j - 1];
                }else{
                    //文本串最后字符与模式串最后两个字符不匹配，则不管模式串最后两个字符
                    if(j >= 2)
                        dp[i][j] = dp[i][j - 2];
                    //匹配则接着对比文本串下一位
                    if(i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
        return dp[len1][len2];
     }
}