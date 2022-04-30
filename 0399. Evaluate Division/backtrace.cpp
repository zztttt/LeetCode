class Solution {
public:
    map<string, vector<pair<string, double>>> adjList;
    set<string> visited;
    
    double dfs(const string& start, const string& end, double val, set<string>& visited){
        //cout << "start:" << start << ", end:" << end << ", val" << val << endl;
        if(start == end && adjList.find(start) != adjList.end()){
            return val;
        }
        
        
        int len = adjList[start].size();
        for(int i = 0; i < len; ++i){
            const pair<string, double>& cur = adjList[start][i];
            if(visited.find(cur.first) == visited.end()){
                visited.insert(cur.first);
                double res = dfs(cur.first, end, val * cur.second, visited);
                visited.erase(cur.first);
                if(res != -1.0){
                    return res;
                }
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        for(int i = 0; i < len; ++i){
            const auto& eq = equations[i];
            adjList[eq[0]].push_back({eq[1], values[i]});
            adjList[eq[1]].push_back({eq[0], 1.0 / values[i]});
        }
        
        vector<double> ret;
        for(auto& query: queries){
            visited.insert(query[0]);
            double res = dfs(query[0], query[1], 1.0, visited);
            visited.erase(query[0]);
            ret.push_back(res);
        }
        
        return ret;
    }
};