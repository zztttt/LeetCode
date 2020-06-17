class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for(int i = 0; i < 32; ++i){
            int cur = n & 1;
            ret += cur;
            n = n >> 1;
        }
        return ret;
    }
};