class Solution {
    public int findDuplicate(int[] v) {
        Arrays.sort(v);
        int len = v.length, index = 1, lastVal = v[0];
        while(index < len){
            if(v[index] == lastVal){
                return v[index];
            }else{
                lastVal = v[index];
                index++;
            }
        }
        return -1;
    }
}