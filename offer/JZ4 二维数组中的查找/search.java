public class Solution {
    public boolean Find(int target, int [][] array) {
        if(array.length == 0 || array[0].length == 0)
            return false;
        int row = array.length, col = array[0].length;
        int i = 0, j = col - 1;
        while(i < row && j >= 0){
            int cur = array[i][j];
            if(cur == target)
                return true;
            else if(cur > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}