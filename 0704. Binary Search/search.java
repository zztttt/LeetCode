class Solution {
    public int search(int[] v, int target) {
        int len = v.length, low = 0, high = len - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(v[mid] == target){
                return mid;
            }else if(v[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
}