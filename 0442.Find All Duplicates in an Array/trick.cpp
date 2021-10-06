class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        int n = nums.size();
        vector<int> ret;
        for(int i = 0; i < n; ++i){
            int cur = abs(nums[i]);
            if(nums[cur - 1] < 0){
                // already existing
                ret.push_back(cur);
            }else{
                // marked as existing
                nums[cur - 1] *= -1;
            }
        }
        return ret;
    }
};