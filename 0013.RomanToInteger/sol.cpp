class Solution {
public:
    int romanToInt(string s) {
        int len = s.size(), ret = 0;
        for(int i = 0; i < len; ++i){
            if(i == len - 1){
                ret += mapping(s[i]);
                break;
            }
            if(mapping(s[i]) < mapping(s[i + 1])){
                ret -= mapping(s[i]);
            }else{
                ret += mapping(s[i]);
            }
        }
        return ret;
    }
    
    int mapping(const char& c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
};