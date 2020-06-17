class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), index = 1, last = v[0];
        for(int i = 1; i < len; ++i){
            if(v[i] != last){
                v[index++] = v[i];
                last = v[i];
            }
        }
        return index;
        /*for(int i = index; i < len; ++i){
            v[i] = 0;
        }*/
    }
};