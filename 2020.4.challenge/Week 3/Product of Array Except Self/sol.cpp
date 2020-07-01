class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int len = v.size();
        int leftPro = 1;
        vector<int> dp(len, 1);
        for(int i = 0; i < len; ++i){
            dp[i] = leftPro;
            leftPro *= v[i];
        }
        int rightPro = 1;
        for(int i = len - 1; i >= 0; --i){
            dp[i] *= rightPro;
            rightPro *= v[i];
        }
        return dp;
    }
};