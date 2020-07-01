class Solution {
public:
    bool canJump(vector<int>& v) {
        if(v.size() == 0)
            return true;
        int len = v.size(), curMax = 0;
        for(int i = 0; i < len; ++i){
            if(curMax < i)
                return false;
            curMax = max(curMax, i + v[i]);
        }
        return true;
    }
};