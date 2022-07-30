class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCount(26, 0);
        for(const string& s: words2) {
            vector<int> charCount = count(s);
            for(int i = 0; i < 26; ++i){
                maxCount[i] = max(maxCount[i], charCount[i]);
            }
        }
        
        vector<string> ret;
        for(const string& s: words1){
            vector<int> charCount = count(s);
            
            bool valid = true;
            for(int i = 0; i < 26; ++i){
                if(charCount[i] < maxCount[i]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ret.push_back(s);
            }
        }
        
        return ret;
    }
    
    vector<int> count(const string& s){
        vector<int> ret(26, 0);
        for(int i = 0; i < 26; ++i){
            ret[i] = std::count(s.begin(), s.end(), 'a' + i);
        }
        return ret;
    }
};