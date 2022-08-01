class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int len = grades.size(), ret = 0;
        for(int n = 1; len >= n; ++n){
            ret++;
            len -= n;
        }
        return ret;
    }
};