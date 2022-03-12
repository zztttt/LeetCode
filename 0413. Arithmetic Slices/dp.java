class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        if(nums.length <= 2)
            return 0;
        int len = nums.length, ret = 0;
        for(int i = 0; i < len - 1; ++i){
            int diff = nums[i + 1] - nums[i], index = i + 1;
            while(index < len){
                if(nums[index] - nums[index - 1] == diff){
                    if(index - i >= 2){
                        ret++;
                    }
                    index++;
                }else{
                    break;
                }
            }
        }
        return ret;
    }
}