class Solution {
public:
    int findMaxLength(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size();
        int count = 0, ret = 0;
        map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < len; ++i){
            int cur = v[i];
            if(cur == 0) count--;
            if(cur == 1) count++;
            if(m.find(count) == m.end())
                m[count] = i;
            else
                ret = max(ret, i - m[count]);
        }
        return ret;
    }
};