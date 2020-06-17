class Solution {
public:
    vector<vector<int>> permute(vector<int> nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        if(len == 0) return ret;
        
        vector<int> visited;
        backtrace(ret, nums, visited);
        
        return ret;
    }
    
    void backtrace(vector<vector<int>>& ret, vector<int> nums, vector<int>& visited){
        int len = nums.size();
        if(visited.size() == len){
            ret.push_back(visited);
                return;
        }
        for(int i = 0; i < len; ++i){
            // not find duplicated ele
            if(find(visited.begin(), visited.end(), nums[i]) == visited.end()){
                visited.push_back(nums[i]);
                backtrace(ret, nums, visited);
                visited.pop_back();
            }
        }
    }
};