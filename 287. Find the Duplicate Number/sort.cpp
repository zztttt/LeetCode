class Solution {
public:
    int findDuplicate(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        sort(v.begin(), v.end());
        int len = v.size(), last = v[0];
        for(int i = 1; i < len; ++i){
            if(v[i] != last){
                last = v[i];
            }else{
                return last;
            }
        }
        return -1;
    }
};