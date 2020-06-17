class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if(n <= 0)
            return vector<int>(n, 0);
        
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
        return ret.size() == n? ret: vector<int>();
    }
};