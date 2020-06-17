class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        if(v.size() == 0)
            return false;
        map<int, int> m;
        for(int i: v){
            if(m.find(i) == m.end()){
                m[i] = 1;
            }else{
                m[i] = m[i] + 1;
            }
            if(m[i] > 1)
                return true;
        }
        return false;

    }
};