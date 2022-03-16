import java.util.Arrays;
public class Solution {
    public int FindGreatestSumOfSubArray(int[] v) {
        if(v.length == 0)
            return 0;
        int len = v.length, ret = 0, tmp = 0;
        for(int i = 0; i < len; ++i){
            tmp = tmp + v[i];
            if(tmp < 0){
                tmp = 0;
            }
            ret = Math.max(ret, tmp);
        }
        return ret != 0? ret : Arrays.stream(v).max().getAsInt();
    }
}