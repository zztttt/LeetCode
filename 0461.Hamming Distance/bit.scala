object Solution {
    def hammingDistance(a: Int, b: Int): Int = {
        // x.asInstanceOf[unsignedInt];
        // y.asInstanceOf[unsignedInt];
        var x = a;
        var y = b;
        var mask: Int = (1 << 31);
        var ret = 0;
        for(i <- 0 until 32){
            if((x & mask) != (y & mask)){
                ret += 1;
            }
            x = x << 1;
            y = y << 1;
        }
        ret;
    }
}