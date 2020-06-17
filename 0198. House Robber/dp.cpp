class Solution {
public:
    int rob(vector<int> v){
        if(v.size() == 0) return 0;
        if(v.size() == 1) return v[0];
        int len = v.size(), ret = 0;
        // max(v[i], v[i-1]+v[i+1]), update to v[i+1]
        for(int i = 0; i < len; ++i){
            int tmp1, tmp2;
            if(i == 0){
                tmp1 = 0;
                tmp2 = 0 + v[0];
            }else if(i == 1){
                tmp1 = v[0];
                tmp2 = 0 + v[i];
            }else{
                tmp1 = v[i - 1];
                tmp2 = v[i - 2] + v[i];
            }
            v[i] = max(tmp1, tmp2);
        }
        return v[len - 1];
    }
};