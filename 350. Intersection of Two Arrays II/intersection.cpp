class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        if(v1.size() == 0 || v2.size() == 0)
            return {};
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int p1 = 0, p2 = 0, len1 = v1.size(), len2 = v2.size();
        vector<int> ret;
        
        while(p1 < len1 && p2 < len2){
            int a = v1[p1], b = v2[p2];
            if(a == b){
                ret.push_back(a);
                p1++;
                p2++;
            }else if(a < b){
                p1++;
            }else{
                p2++;
            }
        }
        
        return ret;
    }
};