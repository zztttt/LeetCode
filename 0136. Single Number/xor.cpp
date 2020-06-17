class Solution {
public:
    int singleNumber(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), ret = v[0];
        for(int i = 1; i < len; ++i){
            ret = ret ^ v[i];
        }

        return ret;
    }
};