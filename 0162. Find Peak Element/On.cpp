class Solution {
public:
    int findPeakElement(vector<int>& v) {
        if(v.size() == 0 )
            return -1;
        if(v.size() == 1)
            return 0;
        int len = v.size();
        for(int i = 0; i < len; ++i){
            // special case
            if(i == 0){
                if(v[0] > v[1])
                    return 0;
            }else if(i == len - 1){
                if(v[len - 1] > v[len - 2])
                    return len - 1;
            }else{
                // from 1 to len-2
                if(v[i] > v[i-1] && v[i] > v[i+1])
                    return i;
            }
        }
        return -1;
    }
};