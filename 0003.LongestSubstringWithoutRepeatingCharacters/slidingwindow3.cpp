class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), ret = 0;
        map<char, int> index;
        unordered_set<char> exists;
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(exists.find(cur) == exists.end()){
                exists.insert(cur);
                index[cur] = i;
            }else{
                int old = index[cur];
                for(auto [key, val]: index){
                    if(val < old){
                        exists.erase(key);
                    }
                }
                index[cur] = i;
            }
            ret = max(ret, (int)exists.size());
        }
        
        return ret;
    }
};