class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for(int i = 0; i < 32; ++i){
            int cur = (n >> i) & 1;
            cur = cur << (31 - i);
            ret = ret | cur;
        }
        return ret;
    }
};