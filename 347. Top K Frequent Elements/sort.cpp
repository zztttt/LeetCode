class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        if(v.size() == 0)
            return {};
        // record frequence
        map<int, int> m;
        for(int i: v){
            if(m.find(i) == m.end())
                m[i] = 1;
            else
                m[i] = m[i] + 1;
        }
        // transfer data into vector
        vector<pair<int, int>> pairs;
        for(map<int, int> ::iterator it = m.begin(); it != m.end(); it++){
            pairs.push_back(pair<int, int>(it->first, it->second));
        }
        // sort by value
        sort(pairs.begin(), pairs.end(), cmp);
        
        // select top k frequent data
        vector<int> ret;
        for(int i = 0; i < k; ++i){
            ret.push_back(pairs[i].first);
        }
        return ret;
    }
    
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};