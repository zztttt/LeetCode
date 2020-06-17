class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        if(n <= 0)
            return false;
        if(pre.size() == 0 || pre[0].size() == 0)
            return true;
        
        vector<int> inDegree(n, 0), ret;
        // mark inDegree in each vertex
        for(vector<int> v: pre){
            int first = v[0], last = v[1];
            inDegree[first]++;;
        }
        // push vertex's inDegree(0) in queue
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(inDegree[i] == 0)
                q.push(i);
        }
        // loop queue
        while(!q.empty()){
            int src = q.front();
            q.pop();
            ret.push_back(src);
            
            for(vector<int> v: pre){
                int first = v[0], last = v[1];
                if(last == src){
                    inDegree[first]--;
                    if(inDegree[first] == 0)
                        q.push(first);
                }
            }
        }
        return ret.size() == n;
    }
};