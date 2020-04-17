class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int ret = 0;
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    ret++;
                }
                
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        int row = grid.size(), col = grid[0].size();
        if(x < 0 || x > row - 1 || y < 0 || y > col - 1)
            return;
        if(visited[x][y])
            return;
        if(grid[x][y] == '1'){
            visited[x][y] = true;
            dfs(grid, visited, x + 1, y);
            dfs(grid, visited, x - 1, y);
            dfs(grid, visited, x, y + 1);
            dfs(grid, visited, x, y - 1);
        }
        
    }
};