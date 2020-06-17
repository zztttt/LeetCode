class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if(len1 < len2 || len1 < 0 || len2 < 0) return -1;
        if(len2 == 0)return 0;
        char start = needle[0];
        int ret = -1;
        for(int i = 0; i < len1 - len2 + 1; i++){
            if(haystack[i] == start){
                if(isMatching(haystack.substr(i, len2), needle)){
                    ret = i;
                    break;
                }
            }    
        }
        return ret;
    }
    
    bool isMatching(string s1, string s2){
        //cout << "s1:" << s1 << "\t s2:" << s2 << endl; 
        int len = s1.size();
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i])
                return false;
        }
        return true;
    }
};