class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        if(v.size() < 3) return {};
        int len = v.size();
        vector<vector<int>> ret;
        sort(v.begin(), v.end());
        
        
        for(int i = 0; i < len - 2; ++i){
            if(i > 0 && v[i] == v[i - 1])
                continue;
            int low = i + 1, high = len - 1, target = 0 - v[i];
            while(low < high){
                if(v[low] + v[high] == target){
                    vector<int> res = vector<int>{v[i], v[low], v[high]};
                    ret.push_back(res);
                    do{
                        high--;
                    }while(high >= 0 && v[high] == v[high + 1]);
                    do{
                        low++;
                    }while(low <= len - 1 && v[low] == v[low - 1]);
                }else if(v[low] + v[high] > target){
                    do{
                        high--;
                    }while(high >= 0 && v[high] == v[high + 1]);
                }else{
                    do{
                        low++;
                    }while(low <= len - 1 && v[low] == v[low - 1]);
                }
            }
        }
        
        return ret;
    }
};