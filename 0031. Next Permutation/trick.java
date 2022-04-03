class Solution {
    public void nextPermutation(int[] v) {
        int len = v.length, index = len - 1;
        // all descending
        while(index >= 1){
            if(v[index] > v[index - 1]){
                break;
            }else{
                index--;
            }
        }
        if(index == 0){
            reverse(v, 0, len - 1);
            return;
        }
        
        int lower = v[index - 1], pos = index;
        while(pos < len){
            if(v[pos] > lower){
                pos++;
            }else{
                break;
            }
        }
        v[index - 1] = v[pos - 1];
        v[pos - 1] = lower;
        reverse(v, index, len - 1);
    }
    
    private void reverse(int[] v, int low, int high){
        while(low < high){
            int tmp = v[low];
            v[low] = v[high];
            v[high] = tmp;
            high--;
            low++;
        }
    }
}