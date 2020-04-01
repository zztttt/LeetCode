class Solution {
public:
    int singleNumber(vector<int>& v) {
        int len = v.size(), ret = v[0];
        for(int i = 1; i < len; ++i){
            ret = ret ^ v[i];
        }
        return ret;
    }
};