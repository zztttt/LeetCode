class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stk = new Stack<>();
        int len = pushed.length, index1 = 0, index2 = 0;
        
        while(index1 < len){
            while(!stk.empty()){
                // System.out.println(stk.toString());
                if(stk.peek() == popped[index2]){
                    stk.pop();
                    index2++;
                }else{
                    break;
                }
            }
            stk.push(pushed[index1]);
            index1++;
        }
        while(!stk.empty()){
            // System.out.println(stk.toString());
            if(stk.peek() == popped[index2]){
                stk.pop();
                index2++;
            }else{
                break;
            }
        }
        
        return stk.empty();
    }
}