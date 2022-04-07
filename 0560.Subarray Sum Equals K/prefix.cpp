class Solution {
public:
    int subarraySum(vector<int>& v, int target) {
        int len = v.size(), sum = 0, ret = 0;
        vector<int> prefix(len + 1, 0); //[0, i)
        for(int i = 1; i < len + 1; ++i){
            prefix[i] = prefix[i - 1] + v[i - 1];
        }
        
        for(int i = 0; i < len; ++i){
            for(int j = i + 1; j < len + 1; ++j){
                if(prefix[j] - prefix[i] == target)
                    ret++;
            }
        }
        return ret;
    }
};