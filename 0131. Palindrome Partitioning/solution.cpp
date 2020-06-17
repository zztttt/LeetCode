class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> cur;
        
        partition(ret, cur, s);
        
        return ret;
    }
    
    void partition(vector<vector<string>>& ret, vector<string>& cur, string s){
        int len = s.size();
        if(len == 0){
            ret.push_back(cur);
            return;
        }
            
        for(int i = 0; i < len; ++i){
            // s[0, i]
            string tmp = s.substr(0, i + 1);
            if(isPalindrome(tmp)){
                cur.push_back(tmp);
                // s[i + 1, len - 1]
                partition(ret, cur, s.substr(i + 1, len - i - 1));
                // backtrace
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        int len = s.size();
        if(len == 0 || len == 1)
            return true;
        int low = 0, high = len - 1;
        while(low <= high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};