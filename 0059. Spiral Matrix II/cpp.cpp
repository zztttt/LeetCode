class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int rlow = 0, rhigh = n - 1, clow = 0, chigh = n - 1;
        int val = 1;
        while(rlow < rhigh && clow < chigh){
            for(int i = clow; i <= chigh; ++i){
                v[rlow][i] = val++;
            }
            for(int i = rlow + 1; i <= rhigh; ++i){
                v[i][chigh] = val++;
            }
            for(int i = chigh - 1; i >= clow; --i){
                v[rhigh][i] = val++;
            }
            for(int i = rhigh - 1; i >= rlow + 1; --i){
                v[i][clow] = val++;
            }
            rlow++;rhigh--;
            clow++;chigh--;
        }
        if(rlow == rhigh && clow == chigh){
            v[rlow][clow] = val;
        }
        return v;
    }
};