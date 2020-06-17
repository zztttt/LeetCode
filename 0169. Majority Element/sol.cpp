class Solution {
public:
    int majorityElement(vector<int>& v) {
        int len = v.size();
        map<int, int> m;
        for(int i: v){
            if(m.find(i) == m.end()){
                m[i] = 1;
                if(m[i] > len / 2)
                    return i;
            }else{
                m[i] = m[i] + 1;
                if(m[i] > len / 2)
                    return i;
            }
        }
        return -1;
    }
};