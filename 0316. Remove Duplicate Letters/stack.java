
class Solution {
    public String removeDuplicateLetters(String ss) {
        int[] lastIndex = new int[26];
        boolean[] isSeen = new boolean[26]; // default false
        Stack<Integer> monoStack = new Stack<>();
        char[] s = ss.toCharArray();
        
        int len = s.length;
        for(int i = 0; i < len; ++i){
            lastIndex[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < len; ++i){
            int cur = s[i] - 'a';
            if(isSeen[cur])
                continue;
            while(!monoStack.empty() && monoStack.peek() > cur && i < lastIndex[monoStack.peek()]){
                isSeen[monoStack.pop()] = false;
            }
            monoStack.push(cur);
            isSeen[cur] = true;
        }
        StringBuilder sb = new StringBuilder();
        while(!monoStack.empty()){
            sb.append((char)(monoStack.pop() + 'a'));
        }
        return sb.reverse().toString();
    }
}