class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int len = matrix.size();
        if(len == 0) return ret;
        
        //layer by layer
        int top = 0, bottom = len - 1, left = 0, right = matrix[0].size()-1;
        while(top <= bottom && left <= right){
            // from left to right
            for(int i = left; i <= right; ++i)
                ret.push_back(matrix[top][i]);
            // from top to bottom
            for(int i = top + 1; i <= bottom; ++i)
                ret.push_back(matrix[i][right]);
            // for no duplicated case
            if(top < bottom && left < right){
                // from right to left
                for(int i = right - 1; i >= left; --i)
                    ret.push_back(matrix[bottom][i]);
                // from left to right
                for(int i = bottom - 1; i >= top + 1; --i)
                    ret.push_back(matrix[i][left]);
            }
            top++;bottom--;
            left++;right--;
        }
        return ret;
    }
};