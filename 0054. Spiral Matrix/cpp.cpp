class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int row = matrix.size(), col = matrix[0].size();
        int rlow = 0, rhigh = row - 1, clow = 0, chigh = col - 1;
        vector<int> v;
        while(rlow < rhigh && clow < chigh){
            for(int i = clow; i <= chigh; ++i){
                v.push_back(matrix[rlow][i]);
            }
            for(int i = rlow + 1; i <= rhigh; ++i){
                v.push_back(matrix[i][chigh]);
            }
            for(int i = chigh - 1; i >= clow; --i){
                v.push_back(matrix[rhigh][i]);
            }
            for(int i = rhigh - 1; i >= rlow + 1; --i){
                v.push_back(matrix[i][clow]);
            }
            rlow++;rhigh--;
            clow++;chigh--;
        }
        if(rlow == rhigh && clow == chigh){
            v.push_back(matrix[rlow][clow]);
        }else if(rlow == rhigh && clow < chigh){
            for(int i = clow; i <= chigh; ++i){
                v.push_back(matrix[rlow][i]);
            }
        }else if(rlow < rhigh && clow == chigh){
            for(int i = rlow; i <= rhigh; ++i){
                v.push_back(matrix[i][clow]);
            }
        }
        return v;
    }
};