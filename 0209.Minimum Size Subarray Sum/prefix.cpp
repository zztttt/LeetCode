class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int len = v.size(), sum = 0, ret = INT_MAX;
        vector<int> prefix(len + 1, 0); //[0, i)
        for(int i = 1; i < len + 1; ++i){
            prefix[i] = prefix[i - 1] + v[i - 1];
        }
        
        for(int i = 1; i < len + 1; ++i){
            for(int j = i- 1; j >= 0; --j){
                //cout << i << "," << j << ":" << prefix[i] - prefix[j] << endl;
                if(prefix[i] - prefix[j] >= target){
                    ret = min(ret, i - j);
                    break;
                }
            }
        }
        return ret == INT_MAX? 0: ret;
    }
};