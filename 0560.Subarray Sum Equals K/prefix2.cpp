class Solution {
public:
    int subarraySum(vector<int>& v, int target) {
        int len = v.size(), ret = 0;
        map<int, int> sumCount;
        sumCount[0] = 1;
        int prefix = 0;
        for(int i = 0; i < len; ++i){
            prefix = prefix + v[i];
            ret += sumCount[prefix - target];
            // update map
            sumCount[prefix]++;
        }
        return ret;
    }
};