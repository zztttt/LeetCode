class Solution {
    public int reverse(int x) {
        int ret = 0;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            //max:2147483647 min:-2147483648
            if(ret > Integer.MAX_VALUE / 10 || (ret == Integer.MAX_VALUE / 10 && pop > 7)){
                return 0;
            }
            if(ret < Integer.MIN_VALUE / 10 || (ret == Integer.MIN_VALUE / 10 && pop < -8)){
                return 0;
            }
            ret = ret * 10 + pop;
        }
        return ret;
    }
}