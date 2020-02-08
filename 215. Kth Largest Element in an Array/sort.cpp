class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        if(v.size() == 0)
            return 0;
        int len = v.size();
        sort(v.begin(), v.end());
        return v[len - k];
    }
};