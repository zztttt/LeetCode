object Solution {
    def uniquePaths(m: Int, n: Int): Int = {
        var dp = Array.fill[Array[Int]](m)(Array.fill(n)(0));
        for(i <- 0 until m){
            dp(i)(0) = 1;
        }
        for(i <- 0 until n){
            dp(0)(i) = 1;
        }
        
        for(i <- 1 until m){
            for(j <- 1 until n){
                dp(i)(j) = dp(i - 1)(j) + dp(i)(j -1);
            }
        }
        dp(m - 1)(n - 1);
    }
}