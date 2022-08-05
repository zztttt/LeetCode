class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        try{
            return LCP(v, 0, v.size() - 1);
        }catch(const exception& e){
            cout << e.what();
            return "exception";
        }
    }
    
    string LCP(const vector<string>& v, int low, int high){
        if(low == high){
            return v[low];
        }
        int mid = low + (high - low) / 2;
        return merge(std::move(LCP(v, low, mid)), std::move(LCP(v, mid + 1, high)));
    }
    
    string merge(string&& s1, string&& s2){
        int len = min(s1.size(), s2.size());
        std::stringstream ss;
        for(int i = 0; i < len; ++i){
            if(s1[i] == s2[i]){
                ss << s1[i];
            }else{
                break;
            }
        }
        
        return ss.str();
    }
};