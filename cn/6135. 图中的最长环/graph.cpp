class Solution {
public:
    int longestCycle(vector<int>& edges) {
        unordered_set<int> used;
        int len = edges.size(), ret = -1;
        for(int i = 0; i < len; ++i){
            if(used.find(i) != used.end()){
                continue;
            }
            int next = i;
            unordered_map<int, int> visited;
            while(next != -1){
                if(used.find(next) != used.end()){
                    break;
                }
                if(visited.find(next) == visited.end()){
                    visited[next] = visited.size();
                    next = edges[next];
                }else{
                    ret = max(ret, (int)(visited.size() - visited[next]));
                    for(auto& [key, _] : visited){
                        used.insert(key);
                    }
                    break;
                }
            }
        }
        return ret;
    }
};