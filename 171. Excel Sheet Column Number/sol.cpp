class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size(), ret = 0;
        for(int i = 0; i < len; ++i){
            ret = ret * 26 + getVal(s[i]);
        }
        return ret;
    }
    int getVal(char c){
        return c - 'A' + 1;
    }
};