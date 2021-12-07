public class Solution {
    private int findIndex(int[] v, int low, int high, int target){
        for(int i = high - 1; i >= low; i--){
            if(v[i] < target)
                return i;
        }
        return low - 1;
    }
    public boolean verify(int[] v, int low, int high){
        //System.out.println(low + "," + high);
        if(low > high)
            return true;
        if(low == high)
            return true;
        int rootVal = v[high];
        int index = findIndex(v, low, high, rootVal);
        // left node is null
        if(index == low - 1)
            return verify(v, low, high - 1);
        if(index == high - 1){
            // right node is null
            for(int i = low; i <= high - 1; ++i){
                if(v[i] > rootVal)
                    return false;
            }
            return verify(v, low, high - 1);
        }
        // left node check
        for(int i = low; i <= index; ++i){
            if(v[i] > rootVal)
                return false;
        }
        // right node check
        for(int i = index + 1; i <= high - 1; ++i){
            if(v[i] < rootVal)
                return false;
        }
        return verify(v, low, index) && verify(v, index + 1, high - 1);
        
    }
    public boolean VerifySquenceOfBST(int [] v) {
        if(v.length == 0)
            return false;
        return verify(v, 0, v.length - 1);
    }
}