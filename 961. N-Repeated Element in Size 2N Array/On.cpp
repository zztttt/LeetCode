class Solution {
public:
    int repeatedNTimes(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size();
        for(int i = 0; i < len - 2; ++i){
            vector<int>::iterator it = getDuplicate(v, i, i + 2);
            if(it != v.end())
                return *it;
        }
        return -1;
    }
    vector<int>::iterator getDuplicate(vector<int>& v, int low, int high){
        set<int> st;
        vector<int>::iterator it = v.begin() + low;
        for(; it != v.end(); it++){
            if(st.find(*it) != st.end())
                return it;
            else{
                st.insert(*it);
            }
        }
        return it;
    }
};