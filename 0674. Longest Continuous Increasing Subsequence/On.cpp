class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), count = 1, ret = 1;
        for(int i = 1; i < len; ++i){
            if(v[i] > v[i - 1]){
                count++;
            }else{
                count = 1;
            }
            ret = max(ret, count);
        }
        return ret;
    }
};