class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            // overflow || underflow
            if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)
            || ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8)){
                ret = 0;
                break;
            }
            ret = ret * 10 + pop;
        }

        return ret;
    }
};