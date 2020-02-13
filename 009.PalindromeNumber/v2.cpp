class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int ret = 0, origin = x;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)){
                return false;
            }
            ret = ret * 10 + pop;
        }
        return ret == origin;
    }
};