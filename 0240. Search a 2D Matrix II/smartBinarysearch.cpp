class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int row = matrix.size(), col = matrix[0].size();
        // start from right top corner
        int i = 0, j = col - 1;
        while(i <= row - 1 && j >= 0){
            int cur = matrix[i][j];
            if(cur == target)
                return true;
            else if(cur < target)
                i++;
            else if(cur > target)
                j--;
        }
        return false;
    }
};