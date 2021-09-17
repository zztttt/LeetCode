class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> ret;
        int row = matrix.size(), col = matrix[0].size();
        int rlow = 0, rhigh = row - 1, clow = 0, chigh = col - 1;
        while(rlow <= rhigh && clow <= chigh){
            // top row
            for(int i = clow; i <= chigh; ++i){
                ret.push_back(matrix[rlow][i]);
            }
            // right col
            for(int i = rlow + 1; i <= rhigh; ++i){
                ret.push_back(matrix[i][chigh]);
            }
            // bottom row
            if(rlow != rhigh){
                for(int i = chigh - 1; i >= clow; --i){
                    ret.push_back(matrix[rhigh][i]);
                }
            }
            // left col
            if(clow != chigh){
                for(int i = rhigh - 1; i >= rlow + 1; --i){
                    ret.push_back(matrix[i][clow]);
                }
            }
            
            rlow++;rhigh--;clow++;chigh--;
        }
        
        return ret;
    }
    void print_v(vector<int>& v){
        for(int i: v){
            cout << i << ",";
        }
        cout << endl;
    }
};