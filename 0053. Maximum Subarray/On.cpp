class Solution {
public:
    int maxSubArray(vector<int>& v) {
        if(v.size() == 0) return 0;
        int len = v.size(), ret = INT_MIN;
        int localSum = 0;
        for(int i = 0; i < len; ++i){
            localSum = localSum + v[i];
            ret = max(ret, localSum);
            if(localSum < 0){
                localSum = 0;
            }
        }

        return ret;
    }
};