class Solution {
public:
    int maxProfit(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), last = v[0], ret = 0;
        for(int i = 1; i < len; ++i){
            if(v[i] > last){
                ret += v[i] - last;
            }
            last = v[i];
        }
        return ret;
    }
};