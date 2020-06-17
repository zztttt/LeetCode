class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        if(v.size() == 0)
            return {};
        vector<int> visited;
        vector<vector<int>> ret;

        backtrace(ret, visited, v, 0);

         return  ret;
    }

    void backtrace(vector<vector<int>>& ret, vector<int>& visited, vector<int> v, int level){
        ret.push_back(visited);

        int len = v.size();
        for(int i = level; i < len; ++i){
            int cur = v[i];
            visited.push_back(cur);
            level++;
            backtrace(ret, visited, v, level);
            visited.pop_back();
        }
    }
};