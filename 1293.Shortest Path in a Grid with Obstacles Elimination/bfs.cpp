class Solution {
private:
    class triplet{
        public:
            int x;
            int y;
            int k;
            triplet(int _x, int _y, int _k): x(_x), y(_y), k(_k){};
    };
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int row = grid.size(), col = grid[0].size();
        if(k > row + col - 2)
            return row + col - 2;
        queue<triplet> q;
        q.push(triplet(0, 0, k));
        set<string> visited;
        
        int ret = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                triplet cur = q.front();
                q.pop();
                int x = cur.x, y = cur.y, k = cur.k;
                if(x == row - 1 && y == col - 1)
                    return ret;
                
                // push valid children
                if(x + 1 <= row - 1){
                    int newK = k - grid[x + 1][y];
                    string state = to_string(x + 1) + "," + to_string(y) + "," + to_string(newK);
                    if(newK >= 0 and visited.find(state) == visited.end())
                    {
                        q.push(triplet(x + 1, y, newK));
                        visited.insert(state);
                    }
                }
                if(x - 1 >= 0){
                    int newK = k - grid[x - 1][y];
                    string state = to_string(x - 1) + "," + to_string(y) + "," + to_string(newK);
                    if(newK >= 0 and visited.find(state) == visited.end())
                    {
                        q.push(triplet(x - 1, y, newK));
                        visited.insert(state);
                    }
                }
                if(y + 1 <= col - 1){
                    int newK = k - grid[x][y + 1];
                    string state = to_string(x) + "," + to_string(y + 1) + "," + to_string(newK);
                    if(newK >= 0 and visited.find(state) == visited.end())
                    {
                        q.push(triplet(x, y + 1, newK));
                        visited.insert(state);
                    }
                }
                if(y - 1 >= 0){
                    int newK = k - grid[x][y - 1];
                    string state = to_string(x) + "," + to_string(y - 1) + "," + to_string(newK);
                    if(newK >= 0 and visited.find(state) == visited.end())
                    {
                        q.push(triplet(x, y - 1, newK));
                        visited.insert(state);
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};