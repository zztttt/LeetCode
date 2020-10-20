class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        String ret = "";
        for(int i = 0; i < len; ++i){
            String s1 = getPalindrome(s, i, i);
            String s2 = getPalindrome(s, i, i + 1);
            if(s1.length() > ret.length()){
                ret = s1;
            }
            if(s2.length() > ret.length()){
                ret = s2;
            }
        }
        return ret;
    }

    private String getPalindrome(String s, int low, int high){
        int len = s.length();
        while(low >= 0 && high <= len - 1){
            char c1 = s.charAt(low), c2 = s.charAt(high);
            if(c1 == c2){
                low--;
                high++;
            }else{
                break;
            }
        }
        //public String substring(int beginIndex, int endIndex)
        //[begin, end)
        return s.substring(low + 1, high);
    }
}