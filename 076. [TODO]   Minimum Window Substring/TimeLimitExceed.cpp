class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> chars = build(t);
        int len = s.size(), charSize = chars.size();
        if(t.size() > len) return "";
        int start = 0;
        string minWindow = "";
        
        map<char, int> m;
        for(int i = 0; i < len; i++){
            char cur = s[i];
            // exist in chars
            if(chars.find(cur) != chars.end()){
                if(m.find(cur) == m.end()){
                    m[cur] = 1;
                }else{
                    m[cur] = m[cur] + 1;
                }
            }else{
                // this char doesn't exist, just continue ?
                //continue;
            }
            
            // contain all, erase front element and decrease map's value
            if(isValid(chars, m)){
                //string tmp = s.substr(start, i - start + 1);// s[start, i]
                while(start <= i){
                    char c = s[start];
                    // decrease element's value if contains more element
                    map<char, int>::iterator it = m.find(c);
                    if(it != m.end()){
                        // value = chars.value, start from here
                        int charsVal = chars[c];
                        assert(charsVal > 0);
                        if(it->second == charsVal){
                            string newWindow = s.substr(start, i - start + 1);
                            // update if smaller
                            if(newWindow.size() < minWindow.size() || minWindow.size() == 0)
                                minWindow = newWindow;
                            break;
                        }else{
                            // decrease if value >= 2
                            it->second = it->second - 1;
                            start++;
                        }
                    }else{
                        // this char doesn't exist in set, just skip it
                        start++;
                    }
                    
                }
            }
        }
        return minWindow;
        
    }
    
    map<char, int> build(string s){
        int len = s.size();
        map<char, int> ret;
        for(int i = 0; i < len; ++i){
            char c = s[i];
            if(ret.find(c) == ret.end())
                ret[c] = 1;
            else
                ret[c] = ret[c] + 1;
        }
        return ret;
    }
    
    // m2 contains m1's all elements, and every value is not less than m1's
    bool isValid(map<char, int> m1, map<char, int> m2){
        if(m1.size() != m2.size())
            return false;
        map<char, int>::iterator it = m1.begin();
        for( ;it != m1.end(); it++){
            if(m2[it->first] < it->second)
                return false;
        }
        return true;
    }
};