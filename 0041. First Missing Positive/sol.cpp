class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = v.size(), index = 0;
        while(index < len && v[index] <= 0){
            index++;
        }
        
        if(index == len || v[index] != 1){
            return 1;
        }
        
        int last = v[index];
        for(int i = index + 1; i < len; ++i){
            if(v[i] == v[i - 1])
                continue;
            if(v[i] != last + 1){
                return last + 1;
            }else{
                last = v[i];
            }
        }
        return v[len - 1] + 1;
    }
};