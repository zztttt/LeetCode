class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() == 0)
            return true;
        int len1 = s.length(), len2 = t.length();
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        for(int i = 0; i < len1 + 1; ++i){
            for(int j = 0; j < len2 + 1; ++j){
                dp[i][j] = false;
            }
        }
        for(int i = 0; i < len2 + 1; ++i){
            dp[0][i] = true;
        }
        
        for(int i = 1; i < len1 + 1; ++i){
            for(int j = 1; j < len2 + 1; ++j){
                if(s.charAt(i - 1) == t.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = dp[i - 1][j] && dp[i][j - 1];
                }
            }
        }
        
        return dp[len1][len2];
    }
}