class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) return 1;
        vector<int> ret(n, 0);
        ret[0] = 1; ret[1] = 2;
        for(int i = 2; i < n; ++i){
            ret[i] = ret[i - 1] + ret[i - 2];
        }
        return ret[n - 1];
        
        
        // interator
        /*if(n == 1 || n == 0) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);*/
    }
};