class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = v.size(), maxLen = 0, index = -1;
        
        vector<int> dp(len + 1, 1);
        vector<int> preIndex(len + 1, -1);
        for(int i = 1; i < len + 1; ++i){
            for(int j = 1; j < i; ++j){
                if(v[i - 1] % v[j - 1] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        preIndex[i] = j;
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                index = i;
            }
        }
        
        vector<int> ret;
        while(index != -1){
            ret.push_back(v[index - 1]);
            index = preIndex[index];
        }
        return ret;
    }
};