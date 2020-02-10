class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>();
        int len = nums.size();
        vector<int> ret(len, 1);
        
        // [a, b, c, d] -> [bcd, cd, d, 1]
        for(int i = len - 2; i >= 0; --i){
            ret[i] = ret[i + 1] * nums[i + 1];
        }
        // [[bcd, cd, d, 1] -> [bcd, acd, abd, abc]
        int pre = nums[0];
        for(int i = 1; i < len; ++i){
            ret[i] = ret[i] * pre;
            pre = pre * nums[i];
        }
        
        return ret;
    }
};