class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int len = s.size(), ret = 0, start = 0, subLen = 0;
        
        map<char, int> m;
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(m.find(cur) != m.end()){
                // valid pos
                if(m[cur] >= start){
                    start = m[cur] + 1;
                }
            }
            m[cur] = i;
            ret = max(ret, i - start + 1);
        }
        
        return ret;
    }
};