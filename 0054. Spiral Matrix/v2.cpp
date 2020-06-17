class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int rlow = 0, rhigh = matrix.size() - 1, clow = 0, chigh = matrix[0].size() - 1;
        vector<int> ret;

        while(rlow <= rhigh && clow <= chigh){
            // top row
            for(int i = clow; i <= chigh; ++i){
                ret.push_back(matrix[rlow][i]);
            }
            // right col
            for(int i = rlow + 1; i <= rhigh; ++i){
                ret.push_back(matrix[i][chigh]);
            }
            // avoid duplicate
            if(rlow != rhigh){
                // bottom row
                for(int i = chigh - 1; i >= rlow; --i){
                    ret.push_back(matrix[rhigh][i]);
                }
            }
            if(clow != chigh){
                // left col
                for(int i = rhigh - 1; i >= rlow + 1; --i){
                    ret.push_back(matrix[i][clow]);
                }
            }
            rlow++;rhigh--;
            clow++;chigh--;
        }

        return ret;
    }
};