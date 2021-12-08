import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        int len = pushA.length;
        Stack<Integer> stk = new Stack<>();
        int index = 0;
        for(int i = 0; i < len; ++i){
            if(pushA[i] != popA[index]){
                stk.push(pushA[i]);
            }else{
                index++;
                while(!stk.isEmpty() && stk.peek() == popA[index]){
                    stk.pop();
                    index++;
                }
            }
        }
        return stk.isEmpty();
    }
}