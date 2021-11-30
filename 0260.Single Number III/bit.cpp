class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for(int i: nums){
            axorb ^= i;
        }
        
        int a = 0, b = 0;
        for(int i = 0; i <= 31; ++i){
            int bitmap = 1 << i;
            //cout << bitmap << endl;
            if((bitmap & axorb) == bitmap){
                for(int i: nums){
                    if((bitmap & i) == bitmap){
                        a ^= i;
                    }else{
                        b ^= i;
                    }
                }
                return {a, b};
                
            }
        }
        return {};
    }
};