class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        bool isNeg = false, start = false;
        for(const char& c: s){
            if(c == ' ' && !start){
                continue;
            }
            if(c == '+' || c == '-'){
                if(start){
                    break;
                }
                isNeg = c == '-';
                start = true;
                continue;
            }
            // invalid
            if(!start && !isDigit(c)){
                ret = 0;
                break;
            }
            if(start && !isDigit(c)){
                break;
            }
            
            // finish
            if(!start && isDigit(c)){
                start = true;
            }
            
            if(start){
                int val = c - '0';
                if(isNeg){
                    if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && -val < INT_MIN % 10)){
                        ret = INT_MIN;
                        break;
                    }
                    ret = ret * 10 - val;
                }else{
                    if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && val > INT_MAX % 10)){
                        ret = INT_MAX;
                        break;
                    }
                    ret = ret * 10 + val;
                }
            }
        }
        return ret;
    }
    
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
};