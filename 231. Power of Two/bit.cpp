class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) 
            return false;
        // 1000000 & 0111111
        return (n & (n - 1)) == 0;
    }
};