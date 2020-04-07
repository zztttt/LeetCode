class Solution {
public:
    int countElements(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        set<int> st;
        int ret = 0, len = v.size();
        for(int i = 0; i < len; ++i){
            int cur = v[i];
            if(st.find(cur) == st.end())
                st.insert(cur);
        }
        for(int i = 0; i < len; ++i){
            if(st.find(v[i] + 1) != st.end())
                ret++;
        }
        return ret;
    }
};