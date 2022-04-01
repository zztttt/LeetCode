class Solution {
    public void reverseString(char[] s) {
        int len = s.length, low = 0, high = len - 1;
        while(low < high){
            char c = s[low];
            s[low] = s[high];
            s[high] = c;
            low++;
            high--;
        }
    }
}