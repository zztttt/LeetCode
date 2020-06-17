class Solution {
public:
    vector<string> letterCombinations(string s) {
		if(s.size() == 0)
            return {};
        int len = s.size();
        vector<string> ret = trans(s[0]);
        
        for(int i = 1; i < len; ++i){
            vector<string> cur = trans(s[i]);
            ret = backtrace(ret, cur);
        }
        
		return ret;
	}
    
    vector<string> backtrace(vector<string> old, vector<string> v){
        int len = v.size(), oldlen = old.size();
        vector<string> ret;
        for(int i = 0; i < len; ++i){
            string cur = v[i];
            for(int j = 0; j < oldlen; ++j){
                ret.push_back(old[j] + cur);
            }
        }
        
        return ret;
    }
	vector<string> trans(char c) {
		vector<string> ret;
		switch (c) {
		case '2':ret = { "a", "b", "c" }; break;
		case '3':ret = { "d", "e", "f" }; break;
		case '4':ret = { "g", "h", "i" }; break;
		case '5':ret = { "j", "k", "l" }; break;
		case '6':ret = { "m", "n", "o" }; break;
		case '7':ret = { "p", "q", "r", "s" }; break;
		case '8':ret = { "t", "u", "v" }; break;
		case '9':ret = { "w", "x", "y", "z" }; break;
		default:break;
		}
		return ret;
	}
};