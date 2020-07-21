public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int len = nums.Length;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for(int i = 0; i < len; ++i){
            if(dic.ContainsKey(nums[i])){
                dic[nums[i]] = i;
            }else{
                dic.Add(nums[i], i);
            }
        }
        int[] ret = new int[2];
        for(int i = 0; i < len; ++i){
            int dst = target - nums[i];
            if(dic.ContainsKey(dst)){
                // not itself
                if(dic[dst] != i){
                    ret[0] = i;
                    ret[1] = dic[dst];
                    return ret;
                }
            }
        }
        return ret;
    }
}