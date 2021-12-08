public class Solution {
    public int GetNumberOfK(int[] v, int target) {
        int len = v.length, low = 0, high = len - 1, ret = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(v[mid] == target){
                for(int i = mid; i < len; ++i){
                    if(v[i] == target)
                        ret++;
                    else
                        break;
                }
                for(int i = mid - 1; i >= 0; i--){
                    if(v[i] == target)
                        ret++;
                    else 
                        break;
                }
                return ret;
            }else if(v[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ret;
    }
}