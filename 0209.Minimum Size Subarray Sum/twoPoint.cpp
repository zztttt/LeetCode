class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), left = 0, sum = 0, ret = INT_MAX;
        for(int i = 0; i < len; ++i){
            sum += nums[i];
            // while, not if !!!
            while(sum >= target){  
                // savely increment
                int right = i;
                cout << "left:" << left << ", right:" << right << endl;
                ret = min(ret, right - left + 1);
                // subtract v[left]
                sum -= nums[left];
                left++;
            }
        }
        return ret == INT_MAX? 0: ret;
    }
};