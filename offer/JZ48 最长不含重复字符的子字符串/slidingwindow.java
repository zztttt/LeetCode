import java.util.*;

public class Solution {
    public int lengthOfLongestSubstring (String s) {
        if(s.length() == 0)
            return 0;
        Map<Character, Integer> map = new HashMap<>();
        map.put(s.charAt(0), 0);
        int len = s.length(), ret = 1, start = 0;
        
        for(int i = 1; i < len; ++i){
            char c = s.charAt(i);
            if(map.containsKey(c)){
                start = map.get(c) + 1;
                removeExpireChar(map, start);
            }
            map.put(c, i);
            ret = Math.max(ret, i - start + 1);
        }
        return ret;
    }
    
    private void removeExpireChar(Map<Character, Integer> map, int index){
        Iterator<Map.Entry<Character, Integer>> iterator = map.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<Character, Integer> it = iterator.next();
            if(it.getValue() < index)
                iterator.remove();
        }
    }
}