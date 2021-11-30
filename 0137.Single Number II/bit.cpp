class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int axorb = 0, ret = 0;
        for(int i: nums){
            axorb ^= i;
        }
        for(int i = 0; i <= 31; ++i){
            int bitmap = 1 << i, count = 0;
            for(int i: nums){
                if((bitmap & i) == bitmap)
                    count++;
            }
            if(count % 3 != 0)
                ret |= bitmap;
        }
        return ret;
    }
};