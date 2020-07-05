import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int ret[] = new int[2];
        for(int i = 0; i < len; ++i){
            map.put(nums[i], i);
        }
        for(int i = 0; i < len; ++i){
            int dst = target - nums[i];
            if(map.containsKey(dst) && map.get(dst) != i){
                ret[0] = i;
                ret[1] = map.get(dst);
                return ret;
            }
        }
        return ret;
    }
}