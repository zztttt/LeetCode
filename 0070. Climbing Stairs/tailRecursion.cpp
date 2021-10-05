class Solution {
public:
    int climbStairs(int n) {
        return tailRecursion(n, 1, 1);
    }
    long long tailRecursion(int n, long long cache1, long long cache2){
        if(n == 0)
            return cache1;
        return tailRecursion(n - 1, cache2, cache1 + cache2);
    }
};