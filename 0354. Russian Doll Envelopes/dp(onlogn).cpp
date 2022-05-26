class Solution {
public:    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // envelopes[i][0] ascending, envelopes[i][1] descending
        auto comparator = [&](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0]? a[1] > b[1] : a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), comparator);
        
        // longest increasing subsequence
        vector<int> LIS;
        for(const vector<int>& envelop: envelopes){
            auto it = std::lower_bound(LIS.begin(), LIS.end(), envelop[1]);
            if(it == LIS.end()){
                LIS.push_back(envelop[1]);
            }else{
                *it = envelop[1];
            }
        }
        
        return LIS.size();
    }
};