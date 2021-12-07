class Solution {
public:
    int rob(vector<int>& v) {
        int len = v.size();
        if(len == 1)
            return v[0];
        else if(len == 2)
            return max(v[0], v[1]);
        v[1] = max(v[0], v[1]);
        for(int i = 2; i < len; ++i){
            if(v[i - 1] > v[i - 2] + v[i]){
                v[i] = v[i - 1];
            }else{
                v[i] = v[i - 2] + v[i];
            }
        }
        return v[len - 1];
    }
};