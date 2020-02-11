class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int last = nums[0], len = nums.size();
        // judge whether start from 0
        if(last != 0)
            return 0;
        for(int i = 1; i < len; ++i){
            if(nums[i] != last + 1)
                return last + 1;
            else{
                last++;
            }
        }
        return last + 1;
    }
};