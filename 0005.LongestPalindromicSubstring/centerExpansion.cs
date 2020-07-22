public class Solution {
    public string LongestPalindrome(string s) {
        int len = s.Length, max = 0;
        string ret = "";
        for(int i = 0; i < len; ++i){
            string s1 = getPalindromic(s, i, i);
            string s2 = getPalindromic(s, i, i + 1);
            if(s1.Length > max){
                ret = s1;
                max = s1.Length;
            }
            if(s2.Length > max){
                ret = s2;
                max = s2.Length;
            }
        }
        return ret;
    }
    string getPalindromic(string s, int low, int high){
        int len = s.Length;
        while(low >= 0 && high <= len - 1){
            char a = s[low], b = s[high];
            if(a == b){
                low--;high++;
            }else
                break;
        }
        return s.Substring(low + 1, high - low - 1);
    }
}