class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ret;
        int len = v.size();
        for(int i = 0; i < len - 2; ++i){
            if(v[i] > 0){
                break;
            }
            if(i >= 1 && v[i] == v[i - 1]){
                continue;
            }
            int target = -v[i], low = i + 1, high = len - 1;
            int local = v[low] + v[high];
            while(low < high){
                local = v[low] + v[high];
                if(local == target){
                    ret.push_back({v[i], v[low], v[high]});
                    while(low < len - 1 && v[low + 1] == v[low]){
                        low++;
                    }
                    while(high > i + 1 && v[high - 1] == v[high]){
                        high--;
                    }
                }
                
                if(local > target){
                    high--;
                }else if(local < target){
                    low++;
                }else{
                    low++;
                    high--;
                }
            }
        }
        
        return ret;
    }
};