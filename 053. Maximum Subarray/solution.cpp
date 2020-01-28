class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        
        int maxVal = INT_MIN, curVal = 0;
        for(int i = 0; i < len; ++i){
            curVal += nums[i];
            maxVal = max(maxVal, curVal);
            if(curVal < 0){
                curVal = 0;
            }
        }
        return maxVal;
    }
};