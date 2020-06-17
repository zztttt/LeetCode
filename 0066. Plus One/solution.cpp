class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int len = digits.size();
        if(len == 0) return ret;
        
        // init
        digits[len - 1] = (digits[len - 1] + 1) % 10;
        int carry = digits[len - 1] == 0? 1:0;
        // update
        for(int i = len-2; i >= 0; --i){
            digits[i] = (digits[i] + carry) % 10;
            // carry = 1 if last carry == 1 and last num == 0 
            carry = (digits[i] == 0 && carry == 1)? 1:0;
        }
        // remain a carry
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};