class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        for(const int& i: nums){
            if(i == 0) 
                a++;
            else if(i == 1) 
                b++;
            else 
                c++;
        }
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            if(a > 0){
                nums[i] = 0;
                a--;
            }else if(b > 0){
                nums[i] = 1;
                b--;
            }else{
                nums[i] = 2;
                c--;
            }
        }
    }
};