class Solution {
public:
    string longestCommonPrefix(vector<string>& ss) {
        if(ss.size() == 0 || ss[0].size() == 0) 
            return "";
        if(ss.size() == 1)
            return ss[0];
        string ret = "";
        int len = ss.size(), pos = 0;
        bool isFinish = false;

        while(!isFinish){
            // mask
            char c = ss[0][pos];
            for(int i = 1; i < len; ++i){
                string cur = ss[i];
                // overflow or diff
                if(pos >= cur.size() || cur[pos] != c){
                    isFinish = true;
                    break;
                }
            }
            if(!isFinish){
                ret = ret + c;
                pos++;
            }
                
        }
        return ret;
    }
};