class Solution {
public:
    int minStartValue(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int startValue = 1, sum = startValue, len = nums.size();
        for(int i = 0; i < len; ++i){
            sum += nums[i];
            if(sum < 1){
                int bias = 1 - sum;
                startValue += bias;
                sum = 1;
            }
        }
        return startValue;
    }
};