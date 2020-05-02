class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> st;
        for(char c: J){
            st.insert(c);
        }
        int len = S.size(), ret = 0;
        for(int i = 0; i < len; ++i){
            if(st.find(S[i]) != st.end())
                ret++;
        }
        return ret;
    }
};