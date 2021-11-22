object Solution {
    def singleNonDuplicate(v: Array[Int]): Int = {
        if(v.length == 1)
            return v(0);
        var len = v.length / 2;
        var low = 0;
        var high = len - 1;
        while(low < high){
            //println(low + "," + high);
            var mid = (low + high) / 2;
            var first = v(mid * 2);
            var second = v(mid * 2 + 1);
            if(first == second){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        // low == high
        if(v(low * 2) != v(low * 2 + 1))
            v(low * 2);
        else
            v(v.length - 1);
    }
}