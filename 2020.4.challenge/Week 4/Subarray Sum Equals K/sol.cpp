class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int len = v.size();
        // sum - count
        map<int, int> m;
        m[0] = 1;
        int sum = 0, ret = 0;
        for(int i = 0; i < len; ++i){
            sum += v[i];
            int target = sum - k;
            if(m.find(target) != m.end()){
                ret += m[target];
            }
            // update map
            if(m.find(sum) == m.end()){
                m[sum] = 1;
            }else{
                m[sum]++;
            }
        }
        return ret;
    }
};