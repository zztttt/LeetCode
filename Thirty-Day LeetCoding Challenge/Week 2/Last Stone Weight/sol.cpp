class Solution {
public:
    class more{
    public:
        bool operator()(int a, int b){
            return a < b;
        }
    };
    int lastStoneWeight(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size();
        priority_queue<int, vector<int>, more> q;
        for(int i = 0; i < len; ++i){
            q.push(v[i]);
        }
        while(q.size() >= 2){
            // x >= y
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if(x == y)
                continue;
            else{
                x = x - y;
                q.push(x);
            }
        }
        if(q.size() ==1)
            return q.top();
        else
            return 0;
    }
    
};