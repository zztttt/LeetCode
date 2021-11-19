class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> bitmap(n + 1, 0);
        for(int i: nums){
            bitmap[i] = true;
        }
        
        vector<int> ret;
        for(int i = 1; i < n + 1; ++i){
            if(!bitmap[i])
                ret.push_back(i);
        }
        return ret;
    }
};