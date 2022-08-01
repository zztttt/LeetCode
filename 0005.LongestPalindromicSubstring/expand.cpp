class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), retLen = 0;
        string ret = "";
        for(int i = 0; i < len; ++i){
            int a = spread(s, i, i);
            if(a > retLen){
                ret = s.substr(i - (a - 1) / 2, a);
                retLen = a;
            }
            int b = spread(s, i, i + 1);
            if(b > retLen){
                ret = s.substr(i - b / 2 + 1, b);
                retLen = b;
            }
        }
        return ret;
    }
    
    int spread(const string& s, int low, int high){
        int len = s.size();
        if(low < 0 || high > len - 1)
            return 0;
        while(low >= 0 && high <= len - 1){
            if(s[low] == s[high]){
                low--;
                high++;
            }else{
                break;
            }
        }
        return high - low - 1;
    }
};