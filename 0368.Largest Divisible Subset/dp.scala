object Solution {
    import scala.collection.mutable.ListBuffer
    def largestDivisibleSubset(v: Array[Int]): List[Int] = {
        scala.util.Sorting.quickSort(v);
        var len = v.length;
        var maxLen = 0;
        var index = -1;
        var dp = Array.fill[Int](len + 1)(1);
        var preIndex = Array.fill[Int](len + 1)(-1);
        
        for(i <- 1 until len + 1){
            for(j <- 1 until i){
                if(v(i - 1) % v(j - 1) == 0){
                    if(dp(j) + 1 > dp(i)){
                        dp(i) = dp(j) + 1;
                        preIndex(i) = j;
                    }
                }
            }
            if(dp(i) > maxLen){
                maxLen = dp(i);
                index = i;
            }
        }
        
        var ret = ListBuffer[Int]();
        while(index != -1){
            ret.addOne(v(index - 1));
            index = preIndex(index);
        }
        
        ret.toList
    }
}