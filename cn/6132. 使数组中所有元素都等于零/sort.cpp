class Solution {
public:
    int minimumOperations(vector<int>& v) {
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int ret = v.size();
        if(v[0] == 0)
            ret--;
        return ret;
    }
};