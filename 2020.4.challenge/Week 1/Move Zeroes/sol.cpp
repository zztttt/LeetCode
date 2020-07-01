class Solution {
public:
    void moveZeroes(vector<int>& v) {
        if(v.size() == 0)
            return;
        int len = v.size(), index = 0;
        for(int i = 0; i < len; ++i){
            int cur = v[i];
            if(cur != 0)
                v[index++] = cur;
        }
        for(int i = index; i < len; ++i){
            v[i] = 0;
        }
    }
};