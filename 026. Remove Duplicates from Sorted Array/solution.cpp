class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)return len;
        sort(nums.begin(), nums.end());
        int last = nums[0], ret = 1, lastPos = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] != last){
                //update num
                ret++;
                last = nums[i];
                //update val
                nums[lastPos] = last;
                lastPos++;
            }
        }
        return ret;
    }
};