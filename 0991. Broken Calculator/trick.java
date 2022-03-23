class Solution {
    public int brokenCalc(int startValue, int target) {
        int ret = 0;

        while(target > startValue){
            if(target == startValue)
                return ret;
            if(target % 2 == 1){
                target = target + 1;
            }else{
                target = target / 2;
            }
            ret++;
        }
        return ret + startValue - target;
    }
}