class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)  return 0;
        int len = s.size(), ret = 0;
        
        bool isNeg = false, start = false;

        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(cur == ' ' && !start){
                continue;
            }

            if(isOp(cur)){
                // multiple op, invalid
                if(start){
                    break;
                }else if(cur == '+'){
                    isNeg = false;
                    start = true;
                }else if(cur == '-'){
                    isNeg = true;
                    start = true;
                }
                continue;
            }

            // invalid case
            if(!start && !isDigit(cur)){
                ret = 0;
                break;
            }else if(start && !isDigit(cur)){
                break;
            }

            // flag to start
            if(!start && isDigit(cur)) 
                start = true;
            // flag to end
            if(start && !isDigit(cur))
                break;

            // normal process
            if(start){
                int push = cur - '0';
                if(isNeg){
                    if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && push > 8)){
                        ret = INT_MIN;
                        break;
                    }
                    ret = ret * 10 - push;
                }else{
                    if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && push > 7)){
                        ret = INT_MAX;
                        break;
                    }
                    ret = ret * 10 + push;
                }
            }
        }      
        return ret;
    }
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    bool isOp(char c){
        return c == '+' || c == '-';
    }
};