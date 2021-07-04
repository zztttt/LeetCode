class Solution {
private:
    int vowelLen = 5;
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    map<char, int> m = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    int mod = 1000000007;
public:
    int countVowelPermutation(int n) {
        // init
        vector<vector<long>> dp(n + 1, vector<long>(vowelLen, 0));
        for(int i = 0; i < n + 1; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j < vowelLen; ++j){
            dp[1][j] = 1;
        }
        // dynamic
        //cout << "start dynamic" << endl;
        for(int i = 2; i < n + 1; ++i){
            for(int j = 0; j < vowelLen; ++j){
                //cout << "i:" << i << ", j:" << vowel[j] << endl;
                switch(vowel[j]){
                    case 'a':
                        // ...ea ...ia ...ua
                        dp[i][j] = dp[i-1][m['e']] % mod + dp[i-1][m['i']] % mod + dp[i-1][m['u']] % mod;
                        break;
                    case 'e':
                        // ...ae ...ie ...
                        dp[i][j] = dp[i-1][m['a']] % mod + dp[i-1][m['i']] % mod;
                        break;
                    case 'i':
                        // ...ei ...oi
                        dp[i][j] = dp[i-1][m['e']] % mod + dp[i-1][m['o']] % mod;
                        break;
                    case 'o':
                        // ...io
                        dp[i][j] = dp[i-1][m['i']] % mod;
                        break;
                    case 'u':
                        // ...iu ...ou
                        dp[i][j] = dp[i-1][m['i']] + dp[i-1][m['o']] % mod;
                        break;
                    default:
                        assert(0);
                }
            }
        }
        long ret = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
        return ret % mod;
    }
};