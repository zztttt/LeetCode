class Solution {
    public int scoreOfParentheses(String s) {
        int len = s.length();
        Stack<Integer> stk = new Stack<>();
        // init val
        stk.push(0);
        for(int i = 0; i < len; ++i){
            char c = s.charAt(i);
            if(c == '('){
                stk.push(0);
            }else if(c == ')'){
                // reduce
                int val = stk.pop();
                if(val == 0){
                    stk.push(stk.pop() + 1);
                }else{
                    stk.push(stk.pop() + 2 * val);
                }
            }
        }
        return stk.pop();
    }
}