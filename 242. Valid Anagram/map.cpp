class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        map<char, int> m;
        int len = s.size();
        // increase
        for(char c: s){
            if(m.find(c) == m.end())
                m[c] = 1;
            else
                m[c] = m[c] + 1;
        }
        // decrease num
        for(char c: t){
            if(m.find(c) == m.end())
                return false;
            else{
                m[c]--;
                if(m[c] < 0)
                    return false;
            }
        }
        // check map
        map<char, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};