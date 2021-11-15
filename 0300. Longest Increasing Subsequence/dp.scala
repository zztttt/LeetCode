object Solution {
    def lengthOfLIS(v: Array[Int]): Int = {
        var len = v.length;
        var ret = 0;
        var dp: Array[Int] = Array.fill[Int](len + 1)(1);
        for(i <- 1 until len + 1){
            for(j <- 1 until i){
                if(v(i - 1) > v(j - 1)){
                    dp(i) = math.max(dp(j) + 1, dp(i));
                }
            }
            ret = math.max(dp(i), ret);
        }
        ret
    }
}