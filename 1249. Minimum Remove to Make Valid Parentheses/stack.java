class Solution {
    public String minRemoveToMakeValid(String s) {
        int len = s.length();
        StringBuilder ret = new StringBuilder(s);
        Stack<Integer> stk = new Stack<Integer>();
        
        for(int i = 0; i < len; ++i){
            if(s.charAt(i) == '('){
                stk.push(i);
            }else if(s.charAt(i) == ')'){
                if(!stk.empty()){
                    stk.pop();
                }else{
                    ret.setCharAt(i, '*');
                }
            }
        }
        
        while(!stk.empty()){
            ret.setCharAt(stk.pop(), '*');
        }
        // System.out.println(ret.toString());
        return ret.toString().replaceAll("\\*", "");
    }
}