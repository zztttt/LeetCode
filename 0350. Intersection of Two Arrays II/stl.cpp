class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        multiset<int> exists(nums1.begin(), nums1.end());
        for(int i: nums2){
            multiset<int>::const_iterator it = exists.find(i);
            if(it != exists.end()){
                exists.erase(it);
                ret.push_back(i);
            }
        }
        return ret;
    }
};