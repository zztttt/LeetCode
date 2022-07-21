class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        set<int> exist;
        int ans1 = 0, ans2 = 0;
        for(int i: nums){
            if(exist.find(i) != exist.end()){
                ans1++;
                exist.erase(i);
            }else{
                exist.insert(i);
            }
        }
        vector<int> ret(2, 0);
        ret[0] = ans1;
        ret[1] = nums.size() - 2 * ans1;
        return ret;
    }
};