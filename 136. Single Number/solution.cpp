class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // a ^ b ^ a = b,  0 ^ b = b
        int ret = 0;
        for(int i: nums){
            ret = ret ^ i;
        }
        return ret;
    }
};