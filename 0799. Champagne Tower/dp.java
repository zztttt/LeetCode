class Solution {
    public double champagneTower(int n, int row, int index) {
        double[][] dp = new double[101][101];
        for(int i = 0; i < 101; ++i){
            for(int j = 0; j < 101; ++j){
                dp[i][j] = 0.0;
            }
        }
        dp[0][0] = n;
        
        for(int i = 0; i < 100; ++i){
            for(int j = 0; j <= i; ++j){
                if(dp[i][j] > 1){
                    double remain = dp[i][j] - 1;
                    dp[i + 1][j] += remain / 2;
                    dp[i + 1][j + 1] += remain / 2;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[row][index];
    }
}