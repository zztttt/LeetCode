public class Solution {
    public int Reverse(int x) {
        int ret = 0;
        while(x != 0){
            int pop = x % 10;
            if(x >= 0){
                if(ret > 214748364 || (ret == 214748364 && pop >= 7))
                    return 0;
                ret = ret * 10 + pop;
            }else{
                if(ret < -214748364 || (ret == -214748364 && pop < -8))
                    return 0;
                ret = ret * 10 + pop;
            }
            x = x / 10;
        }
        return ret;
    }
}