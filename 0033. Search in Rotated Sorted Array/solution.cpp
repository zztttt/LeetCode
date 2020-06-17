class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), low = 0, high = len - 1;
        if(len == 0)
            return -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < nums[high]){
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }else{
                if(target < nums[mid] && target >= nums[low] )
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }

};