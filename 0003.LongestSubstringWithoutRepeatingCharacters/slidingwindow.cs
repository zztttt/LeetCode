public class Solution {
    public int LengthOfLongestSubstring(string s) {
        if(s.Length == 0)
            return 0;
        int len = s.Length, ret = int.MinValue, start = 0, subLen = 0;
        Dictionary<char, int> map = new Dictionary<char, int>();
        
        for(int i = 0; i < len; ++i){
            char c = s[i];
            // exist
            if(map.ContainsKey(c)){
                // valid
                if(map[c] >= start){
                    // slide window
                    start = map[c] + 1;
                }
            }
            map[c] = i;
            subLen = i - start + 1;
            if(subLen > ret)
                ret = subLen;
        }
        return ret;
    }
}