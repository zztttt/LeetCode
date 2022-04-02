class Solution {
    private boolean check(String s, int low, int high){
        while(low < high){
            if(s.charAt(low) == s.charAt(high)){
                low++;
                high--;
            }else{
                return false;
            }
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        if(s.length() == 0)
            return true;
        int len = s.length(), low = 0, high = len - 1;
        while(low < high){
            if(s.charAt(low) == s.charAt(high)){
                low++;
                high--;
            }else{
                return check(s, low, high - 1) || check(s, low + 1, high);
            }
        }
        return true;
    }
}