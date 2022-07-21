class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        map<char, int> index;
        set<char> exists;
        int start = 0, ret = 0;
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            map<char, int>::iterator it = index.find(cur);
            // exists and valid
            if(it != index.end() && it->second >= start){
                start = it->second + 1;
            }
            index[cur] = i;
            ret = max(ret, i - start + 1);
        }
        return ret;
    }
};