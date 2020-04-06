class Solution {
public:
    // mask:pos
    map<string, int> m;
    
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        if(v.size() == 0)
            return {};
        vector<vector<string>> ret;
        for(string s: v){
            string old = s;
            sort(s.begin(), s.end());
            // new mask
            if(m.find(s) == m.end()){
                int pos = ret.size();
                ret.push_back(vector<string>(1, old));
                m[s] = pos;
            }else{
                int pos = m[s];
                ret[pos].push_back(old);
            }
        }
        
        return ret;
    }
};