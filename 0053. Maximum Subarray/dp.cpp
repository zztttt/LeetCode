class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), ret = nums[0], curMax = nums[0];
        for(int i = 1; i < len; ++i){
            curMax = max(nums[i], curMax + nums[i]);
            ret = max(ret, curMax);
        }
        return ret;
    }
};