class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return binary(nums, 0, nums.size() - 1);
    }
    int binary(const vector<int>& nums, int low, int high){
        if(low > high)
            return -1;
        //cout << "low:" << low << ",high" << high << endl;
        int len = nums.size(), mid = low + (high - low) / 2;
        if(mid >= 1 && mid <= len - 2){
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
        }else if(mid == 0){
            if(nums[mid] != nums[mid + 1])
                return nums[mid];
        }else{
            // mid == len - 1
            if(nums[mid] != nums[mid - 1])
                return nums[mid];
        }
        
        int left = binary(nums, low, mid - 1);
        if(left != -1)
            return left;
        return binary(nums, mid + 1, high);
    }
};