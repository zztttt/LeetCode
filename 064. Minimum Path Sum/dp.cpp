class Solution {
public:
    int ret = INT_MAX;
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int row = grid.size(), col = grid[0].size();
        //vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 1; i < col; ++i){
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        }
        for(int i = 1; i < row; ++i){
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[row - 1][col - 1];
    }

};