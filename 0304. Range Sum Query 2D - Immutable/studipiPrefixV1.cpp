class NumMatrix {
public:
    map<pair<int, int>, int> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return;
        }
        int row = matrix.size(), col = matrix[0].size();
        pair<int, int> p = {0, 0};
        prefix[p] = matrix[0][0];
        for(int i = 1; i < row; ++i){
            pair<int, int> pos = {i, 0}, pre = {i - 1, 0};
            prefix[pos] = prefix[pre] + matrix[i][0];
        }
        
        for(int j = 1; j < col; ++j){
            pair<int, int> pos = {0, j}, pre = {0, j - 1};
            prefix[pos] = prefix[pre] + matrix[0][j];
        }
        
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                pair<int, int> pos = {i, j}, left = {i, j - 1}, upper = {i - 1, j}, leftUpper = {i - 1, j - 1};
                prefix[pos] = prefix[left] + prefix[upper] - prefix[leftUpper] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 >= 1 && col1 >= 1){
            pair<int, int> pos = {row2, col2}, left = {row2, col1 - 1}, upper = {row1 - 1, col2}, leftUpper = {row1 - 1, col1 - 1};
            return prefix[pos] - prefix[left] - prefix[upper] + prefix[leftUpper];
        }else if(row1 == 0 && col1 > 0){
            pair<int, int> pos = {row2, col2}, left = {row2, col1 - 1};
            return prefix[pos] - prefix[left];
        }else if(col1 == 0 && row1 > 0){
            pair<int, int> pos = {row2, col2}, upper = {row1 - 1, col2};
            return prefix[pos] - prefix[upper];
        }else{
            pair<int, int> pos = {row2, col2};
            return prefix[pos];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */