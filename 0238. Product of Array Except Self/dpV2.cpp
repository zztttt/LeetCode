class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        if(v.size() == 0)
            return {};
        int len = v.size(), leftProduct = 1, rightProduct = 1;
        vector<int> dp(len, 1);
        for(int i = 1; i < len; ++i){
            leftProduct = leftProduct * v[i - 1];
            dp[i] = dp[i] * leftProduct;
        }
        for(int i = len - 2; i >= 0; --i){
            rightProduct = rightProduct * v[i + 1];
            dp[i] = dp[i] * rightProduct;
        }

        return dp;
    }
};