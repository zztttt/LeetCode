class Solution {
public:
    int subarraySum(vector<int>& v, int target) {
        if(v.size() == 0)
            return 0;
        int ret = 0, len = v.size(), sum = 0;
        map<int, int> m;
        m[0] = 1; // init. if sum[0, i] == target
        
        for(int i = 0; i < len; ++i){
            sum += v[i];
            if(m.find(sum - target) != m.end())
                ret += m[sum - target];
            if(m.find(sum) == m.end())
                m[sum] = 1;
            else
                m[sum]++;
        }
        return ret;
    }
};