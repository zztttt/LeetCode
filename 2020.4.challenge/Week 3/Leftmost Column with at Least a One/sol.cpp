/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& matrix) {
        vector<int> dimensions = matrix.dimensions();
        int row = dimensions[0], col = dimensions[1];
        int low = 0, high = col - 1;
        for(int j = col - 1; j >= 0; --j){
            bool allZero = true;
            int i = 0;
            for(; i < row; ++i){
                if(matrix.get(i, j) == 1){
                    allZero = false;
                    break;
                }
            }
            if(j == col - 1 && allZero)
                return -1;
            if(j != col - 1 && allZero && i == row){
                return j + 1;
            }
            if(j == 0 && !allZero)
                return 0;
        }
        
        return -1;
    }
};