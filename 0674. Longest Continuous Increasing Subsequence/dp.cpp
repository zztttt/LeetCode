class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int len = v.size(), ret = 1, count = 1;
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