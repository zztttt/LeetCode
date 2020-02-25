class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if(v.size() == 0) return {};
        int len = v.size();
        
        return LCP(v, 0, len - 1);
    }
    
    string LCP(vector<string> v, int low, int high){
        if(low == high){
            return v[low];
        }else{
            int mid = (low + high) / 2;
            return getCommon(LCP(v, low, mid), LCP(v, mid + 1, high));
        }
    }
    
    string getCommon(string a, string b){
        int len1 = a.size(), len2 = b.size(), last = -1;
        for(int i = 0; i < len1 && i < len2; ++i){
            if(a[i] == b[i]){
                last = i;
            }else{
                break;
            }
        }
        
        return a.substr(0, last + 1);
    }
};