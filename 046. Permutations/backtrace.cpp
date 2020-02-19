class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        if(v.size() == 0)
            return {};
        int len = v.size();
        vector<int> visited;
        vector<vector<int>> ret;
        backtrace(ret, visited, v);

        return ret;
    }

    void backtrace(vector<vector<int>>& ret, vector<int>& visited, vector<int> v){
        // finish
        if(visited.size() == v.size()){
            ret.push_back(visited);
            return;
        }

        int len = v.size();
        for(int i = 0; i < len; ++i){
            int cur = v[i];
            // not visited val
            if(find(visited.begin(), visited.end(), cur) == visited.end()){
                visited.push_back(cur);
                backtrace(ret, visited, v);
                visited.pop_back();
            }
        }
    }
};