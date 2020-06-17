class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), head = 0, tail = len - 1, i = 0;
        if(len == 0) return;
        
        while(i <= tail){
            if(nums[i] == 0){
                swap(nums, head, i);
                head++;i++;
            }else if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums, tail, i);
                tail--;
            }else{
                assert(0);
            }
        }
        
        
        // two-pass algorithm
        /*int a = 0, b = 0, c = 0, len = nums.size();
        if(len == 0) return;
        for(int i = 0; i < len; ++i){
            if(nums[i] == 0) ++a;
            if(nums[i] == 1) ++b;
            if(nums[i] == 2) ++c;
        }
        for(int i = 0; i < a; ++i){
            nums[i] = 0;
        }
        for(int i = a; i < a + b; ++i){
            nums[i] = 1;
        }
        for(int i = a + b; i < a + b + c; ++i){
            nums[i] = 2;
        }*/
    }
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};