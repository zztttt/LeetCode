class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        if(v.size() < 3)
            return false;
        int len = v.size();
        vector<int> dp(len, 1);

        for(int i = 1; i < len; ++i){
            for(int j = 0; j < i; ++j){
                if(v[i] > v[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] >= 3)
                return true;
        }
        return false;
    }
};