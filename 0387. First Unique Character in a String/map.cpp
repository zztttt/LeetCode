class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        int len = s.size();
        map<char, int> m;
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(m.find(cur) == m.end()){
                m[cur] = 1;
            }else{
                m[cur] = m[cur] + 1;
            }
        }
        
        for(int i = 0; i < len; ++i){
            if(m[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};