class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0)
            return 0;
        int len = s.size(), ret = 1, last = 0, index = 0;
        while(index < len){
            char c = s[index];
            while(index < len && s[index] == c){
                ret = max(ret, index - last + 1);
                index++;
            }
            last = index;
        }
        return ret;
    }
};