class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len <= 0) return 1;
        int i = 0;
        while(i < len && nums[i] <= 0){
            i++;
        }
        if(i == len) return 1;
        
        // not start from 1
        if(nums[i] != 1) return 1;
        
        // start from 1
        int last = 1;
        for(int j = i; j < len; j++){
            if(nums[j] == last)
                continue;
            else if(nums[j] == last + 1){
                last++;
            }else
                break;
        }
        return last + 1;
    }
};