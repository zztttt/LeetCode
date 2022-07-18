class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 1; j < col; ++j){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        int ret = 0;
        for(int i = 0; i < col; ++i){
            for(int j = i; j < col; ++j){
                map<int, int> counter = {{0, 1}};
                int prefix = 0;
                for(int k = 0; k < row; ++k){
                    prefix += (i > 0)? (matrix[k][j] - matrix[k][i - 1]) : matrix[k][j];
                    ret += counter[prefix - target];
                    // update map
                    counter[prefix]++;
                }
            }
        }
        return ret;
    }
};