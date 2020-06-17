class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        if(v.size() == 0)
            return false;
        int len = v.size();
        sort(v.begin(), v.end());
        for(int i = 1; i < len; ++i){
            if(v[i] == v[i - 1])
                return true;
        }
        return false;
    }
};