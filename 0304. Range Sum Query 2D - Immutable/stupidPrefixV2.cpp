class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return;
        }
        int row = matrix.size(), col = matrix[0].size();
        prefix = vector<vector<int>>(row, vector<int>(col, 0));
        
        prefix[0][0] = matrix[0][0];
        for(int i = 1; i < row; ++i){
            prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
        }
        
        for(int j = 1; j < col; ++j){
            prefix[0][j] = prefix[0][j - 1] + matrix[0][j];
        }
        
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + matrix[i][j]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 >= 1 && col1 >= 1){
            return prefix[row2][col2] - prefix[row2][col1 - 1] - prefix[row1 - 1][col2] + prefix[row1 - 1][col1 - 1];
        }else if(row1 == 0 && col1 > 0){
            return prefix[row2][col2] - prefix[row2][col1 - 1];
        }else if(col1 == 0 && row1 > 0){
            pair<int, int> pos = {row2, col2}, upper = {row1 - 1, col2};
            return prefix[row2][col2] - prefix[row1 - 1][col2];
        }else{
            return prefix[row2][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */