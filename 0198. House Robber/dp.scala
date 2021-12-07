object Solution {
    def rob(v: Array[Int]): Int = {
        var len = v.length;
        if(len == 1)
            return v(0);
        else if(len == 2)
            return math.max(v(0), v(1));
        v(1) = math.max(v(0), v(1));
        for(i <- 2 until len){
            if(v(i - 1) > v(i - 2) + v(i))
                v(i) = v(i - 1);
            else
                v(i) = v(i - 2) + v(i);
        }
        return v(len - 1);
    }
}