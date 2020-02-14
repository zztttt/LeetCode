class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        if(v.size() < 3) return {};
        int len = v.size();
        vector<vector<int>> ret;
        sort(v.begin(), v.end());
        
        for(int i = 0; i < len - 2; ++i){
            // skip duplicated val
            if(i > 0 && v[i] == v[i - 1])
                continue;
            int left = i + 1, right = len - 1, target = -v[i];
            while(left < right){
                if(v[left] + v[right] == target){
                    vector<int> res = {v[i], v[left], v[right]};
                    ret.push_back(res);
                    do{
                        left++;
                    }while(left < right && v[left] == v[left - 1]);
                }
                else if(v[left] + v[right] < target){
                    do{
                        left++;
                    }while(left < right && v[left] == v[left - 1]);
                }
                else{
                    do{
                        right--;
                    }while(left < right && v[right] == v[right + 1]);
                }
            }
        }

        return ret;
    }
};