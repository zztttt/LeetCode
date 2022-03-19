class Solution {
    public int[] nextGreaterElements(int[] nums) {
        // index
        Stack<Integer> monoStack = new Stack<>();
        Set<Integer> visited = new HashSet<>();
        int len = nums.length;
        int[] ret = new int[len];
        int[] v = new int[2 * len - 1];
        Arrays.fill(ret, -1);
        for(int i = 0; i < v.length; ++i){
            v[i] = nums[i % len];
        }

        for(int i = 0; i < v.length; ++i){
            int cur = v[i];
            while(!monoStack.empty() && v[monoStack.peek() % len] < cur){
                if(!visited.contains(monoStack.peek() % len)){
                    int index = monoStack.pop();
                    ret[index] = cur;
                    visited.add(index);
                }else{
                    monoStack.pop();
                }
            }
            monoStack.push(i);
        }
        
        return ret;
    }
}