class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> ret;
        vector<string> group;
        if(len == 0) return ret;
        
        map<string, vector<string>> m;
        for(int i = 0; i < len; ++i){
            checkAndPush(strs[i], m);
        }
        
        for(map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++){
            ret.push_back(it->second);
        }
        return ret;
    }

    void checkAndPush(string src, map<string, vector<string>>& m){
        string dst = src;
        sort(dst.begin(), dst.end());  
        
        map<string, vector<string>>::iterator it = m.find(dst);
        //not found
        if(it == m.end()){
            m[dst] = vector<string>(1, src);
        }else{
            m[dst].push_back(src);
        }   
    }
};