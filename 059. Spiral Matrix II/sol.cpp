class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, -1));
        int count = 1;
        int rlow = 0, rhigh = n - 1, clow = 0, chigh = n - 1;

        while(rlow <= rhigh && clow <= chigh){
            // top row
            for(int i = clow; i <= chigh; ++i){
                ret[rlow][i] = count++;
            }
            // right col
            for(int i = rlow + 1; i <= rhigh; ++i){
                ret[i][chigh] = count++;
            }
            // avoid duplicate
            if(rlow != rhigh){
                // bottom row
                for(int i = chigh - 1; i >= rlow; --i){
                    ret[rhigh][i] = count++;
                }
            }
            if(clow != chigh){
                // left col
                for(int i = rhigh - 1; i >= rlow + 1; --i){
                    ret[i][clow] = count++;
                }
            }
            rlow++;rhigh--;
            clow++;chigh--;
        }

        return ret;
    }
};