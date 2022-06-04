class Solution {
public:
    int n;
    
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        vector<vector<string>> ret;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        vector<int> valid(n, 1), valid_45(2 * n - 1, 1), valid_135(2 * n - 1, 1);
        
        backtrace(grid, ret, 0, valid, valid_45, valid_135);
        return ret;
    }
    
    void backtrace(vector<vector<char>>& grid, vector<vector<string>>& ret, int row, vector<int>& valid, vector<int>& valid_45, vector<int>& valid_135){
        if(row == n){
            vector<string> tmp;
            for(int i = 0; i < n; ++i){
                tmp.push_back(string(grid[i].begin(), grid[i].end()));
            }
            ret.push_back(tmp);
            return;
        }
        
        for(int col = 0; col < n; ++col){
            if(valid[col] && valid_45[col + row] && valid_135[(n - row - 1) + col]){
                valid[col] = valid_45[col + row] = valid_135[(n - row - 1) + col] = 0;
                grid[row][col] = 'Q';
                backtrace(grid, ret, row + 1, valid, valid_45, valid_135);
                grid[row][col] = '.';
                valid[col] = valid_45[col + row] = valid_135[(n - row - 1) + col] = 1;
            }
        }
    }
};