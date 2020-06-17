class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0;
        bool isNeg = (dividend >= 0) != (divisor > 0);
        
        if(dividend != INT_MIN && divisor != INT_MIN && divisor != 0){
            dividend = abs(dividend);
            divisor = abs(divisor);
            
            for(int i = 0; i < 32; i++){
                ret <<= 1;
                if(dividend >> (31 - i) >= divisor){
                    dividend -= (divisor << (31 - i));
                    ++ret;
                }
            }
            
        }else{
            // special case
            if(divisor == 0)
                return INT_MAX;
            if(dividend == INT_MIN && divisor == -1)
                return INT_MAX;
            if(divisor == INT_MIN)
                return dividend == INT_MIN ? 1 : 0;
            
            if(divisor > 0)
                divisor = - divisor;
            for(int i = 0; i < 32; i++) {
                ret <<= 1;
                if((dividend >> (31 - i)) <= divisor) {
                    dividend -= (divisor << (31 - i));
                    ++ret;
                }
            }  
        }
        return isNeg? -ret:ret;
    }
};