class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if(row == 0 || col == 0) return;
        bool firstRowZero = false, firstColZero = false;
        // travel first col
        for(int i = 0; i < row; ++i){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }
        // travel first row
        for(int i = 0; i < col; ++i){
            if(matrix[0][i] == 0){
                firstRowZero = true;
                break;
            }
        }
        
        // mask this row or col whether need to be clear in first row and col
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // clear
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        // clear edge
        for(int i = 0; i < row; ++i){
            if(firstColZero){
                matrix[i][0] = 0;
            }
        }
        for(int i = 0; i < col; ++i){
            if(firstRowZero){
                matrix[0][i] = 0;
            }
        }
    }
};