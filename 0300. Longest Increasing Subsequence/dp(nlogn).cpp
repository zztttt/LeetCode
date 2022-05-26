class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> LIS;
        for(int i = 0; i < len; ++i){
            auto it = std::lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if(it == LIS.end()){
                LIS.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return LIS.size();
    }
};