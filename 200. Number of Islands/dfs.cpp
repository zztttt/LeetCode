class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int row = grid.size(), col = grid[0].size(), ret = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                // find island, dfs
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1)
            return;
        if(grid[i][j] != '1')
            return;
        else{
            grid[i][j] = '0';
            
            dfs(grid, i-1, j);
            dfs(grid, i+1, j);
            dfs(grid, i, j-1);
            dfs(grid, i, j+1);
        }
    }
};