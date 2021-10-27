class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), start = 0, end = len - 1, i = 0;
        while(i <= end){
            if(nums[i] == 0){
                swap(nums, start, i);
                start++; i++;
            }else if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums, end, i);
                end--;
            }
        }
    }
    void swap(vector<int>& v, int a, int b){
        int tmp = v[a];
        v[a] = v[b];
        v[b] = tmp;
    }
};