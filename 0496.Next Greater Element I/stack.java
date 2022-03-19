class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> monotonicStack = new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();
        
        int len1 = nums1.length, len2 = nums2.length;
         int[] ret = new int[len1];
        for(int i: nums2){
            while(monotonicStack.size() > 0 && monotonicStack.peek() < i){
                map.put(monotonicStack.pop(), i);
            }
            monotonicStack.push(i);
        }
        
        for(int i = 0; i < len1; ++i){
            if(map.containsKey(nums1[i])){
                ret[i] = map.get(nums1[i]);
            }else{
                ret[i] = -1;
            }
        }
        return ret;
    }
}