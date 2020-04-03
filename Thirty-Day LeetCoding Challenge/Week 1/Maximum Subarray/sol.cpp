class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int ret = INT_MIN, len = v.size();
        int cur = 0;
        for(int i = 0; i < len; ++i){
            cur = cur + v[i];
            ret = max(ret, cur);
            if(cur < 0)
                cur = 0;
        }
        
        return ret;
    }
};