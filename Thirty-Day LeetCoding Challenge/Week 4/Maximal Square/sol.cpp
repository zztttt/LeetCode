class Solution {
public:
    int ret = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == '1')
                    dfs(matrix, i, j, 1);
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& matrix, int i, int j, int length){
        int row = matrix.size(), col = matrix[0].size();
        int rend = i + length - 1, cend = j + length - 1;
        if(rend >= row || cend >= col){
            return;
        }
        bool isValid = true;
        for(int p = i; p <= rend; ++p){
            if(matrix[p][cend] == '0'){
                isValid = false;
                break;
            }
        }
        for(int p = j; p <= cend; ++p){
            if(matrix[rend][p] == '0'){
                isValid = false;
                break;
            }
        }
        
        if(isValid){
            ret = max(ret, length * length);
            dfs(matrix, i, j, length + 1);
            return;
        }else{
            
        }
        
    }
};