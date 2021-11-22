class Solution {
public:
    int hammingDistance(int a, int b) {
        unsigned int x = a;
        unsigned int y = b;
        int ret = 0;
        unsigned int mask = (1 << 31);
        for(int i = 0; i < 32; ++i){
            if((x & mask) != (y & mask)){
                ret++;
            }
            x = x << 1;
            y = y << 1;
        }
        return ret;
    }
};