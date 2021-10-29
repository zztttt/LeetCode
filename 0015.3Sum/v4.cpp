class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        return threeSumTarget(v, 0);
        
    }
    vector<vector<int>> threeSumTarget(vector<int>& v, int target){
        if(v.size() < 3)
            return {};
        sort(v.begin(), v.end());
        vector<vector<int>> ret;
        
        int len = v.size();
        for(int i = 0; i < len; ++i){
            if(i > 0 && v[i] == v[i - 1])
                continue;
            int low = i + 1, high = len - 1, cur = v[i];
            while(low < high){
                //cout << "low:" << low << ", high:" << high << endl;
                int sum = cur + v[low] + v[high];
                if(sum == 0){
                    ret.push_back(vector<int>{cur, v[low], v[high]});
                    int preLow = v[low], preHigh = v[high];
                    while(low < len && v[low] == preLow){
                        low++;
                    }
                    while(high >= 0 && v[high] == preHigh){
                        high--;
                    }
                    //cout << "hit" << endl;
                }else if(sum < 0){
                    low++;
                }else{
                    high--;
                }
            }
        }
        
        return ret;
    }
};