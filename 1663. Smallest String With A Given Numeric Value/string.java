class Solution {
    public String getSmallestString(int n, int k) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i){
            sb.append('a');
        }
        k = k - n; // 'a' = 1
        
        int index = n - 1;
        while(k > 0){
            if(k > 25){
                k = k - 25;
                sb.setCharAt(index, 'z');
            }else{
                sb.setCharAt(index, (char)('a' + k));
                k = 0;
            }
            index--;
        }
        return sb.toString();
    }
}