class Solution {
public:
    int maxProduct(vector<int>& v) {
        if(v.size() == 0) return 0;
        int len = v.size(), maxV = v[0], minV = v[0], ret = maxV;
        for(int i = 1; i < len; ++i){
            if(v[i] < 0){
                int tmp = minV;
                minV = maxV;
                maxV = tmp;
            }
            maxV = max(v[i], maxV * v[i]);
            minV = min(v[i], minV * v[i]);
            // dynamic update
            ret = max(ret, maxV);
        }
        return ret;
    }
};