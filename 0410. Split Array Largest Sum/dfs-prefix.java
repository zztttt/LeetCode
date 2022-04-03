class Solution {
    public int splitArray(int[] v, int m) {
        int len = v.length, sum = 0;
        int[] prefix = new int[len + 1];
        prefix[0] = 0;
        for(int i = 1; i < len + 1; ++i){
            prefix[i] = prefix[i - 1] + v[i - 1];
        }
        int[][] cache = new int[len][m + 1];
        return dfs(v, prefix, cache, 0, m);
    }
    
    public int dfs(int[] v, int[] prefix, int[][] cache, int index, int m){
        int len = v.length, ret = Integer.MAX_VALUE;
        if(m == 1){
            return prefix[len] - prefix[index];
        }
        if(cache[index][m] != 0){
            return cache[index][m];
        }
        
        for(int i = index; i <= len - m; ++i){
            // v[i] is in left part
            int left = prefix[i + 1] - prefix[index];
            // right starts from index:i + 1
            int right = dfs(v, prefix, cache, i + 1, m - 1);
            ret = Math.min(ret, Math.max(left, right));
            if(left >= ret){
                break;
            }
        }
        cache[index][m] = ret;
        return ret;
    }
}