class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0)
            return false;
        int rlow = 0, rhigh = array.size() - 1, clow = 0, chigh = array[0].size() - 1;
        int row = 0, col = chigh;
        while(rlow <= row && row <= rhigh && clow <= col && col <= chigh){
            //cout << "row:" << row << ", col:" << col << endl;
            int mid = array[row][col];
            if(mid == target)
                return true;
            else if(mid < target){
                row = row + 1;
            }else{
                col = col - 1;
            }
        }
        return false;
    }
};