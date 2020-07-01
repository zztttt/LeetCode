class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2)
            return true;
        int len = coordinates.size();
        double dx = (double)(coordinates[1][0] - coordinates[0][0]);
        double dy = (double)(coordinates[1][1] - coordinates[0][1]);
        
        vector<int> last = coordinates[1];
        for(int i = 2; i < len; ++i){
            vector<int> cur = coordinates[i];
            float y = (float)(cur[1] - last[1]), x = (float)(cur[0] - last[0]);
            if(y / x != dy / dx)
                return false;
            last = cur;
        }
        return true;
    }
};