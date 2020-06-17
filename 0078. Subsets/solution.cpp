class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        vector<int> visited;
        
        backtrace(ret, nums, visited, 0);
        return ret;
    }
    
    void backtrace(vector<vector<int>>& v, vector<int> nums, vector<int>& visited, int level){
        int len = nums.size();
        v.push_back(visited);
        
        for(int i = level; i < len; ++i){
            int cur = nums[i];
            
            visited.push_back(cur);
            level++;
            backtrace(v, nums, visited, level);
            visited.pop_back();
            
        }
    }
};