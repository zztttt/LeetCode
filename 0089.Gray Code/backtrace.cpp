class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0};
        set<int> isVisited;
        isVisited.insert(0);
        backtrace(ret, n, isVisited);
        return ret;
    }
    
    bool backtrace(vector<int>& ret, int n, set<int>& isVisited){
        if(ret.size() == (1 << n))
            return true;
        int cur = ret.back();
        for(int i = 0; i < 32; ++i){
            int next = cur ^ (1 << i);
            if(isVisited.find(next) == isVisited.end()){
                isVisited.insert(next);
                ret.push_back(next);
                // if valid sequence found no need to search any further
                if(backtrace(ret, n, isVisited))
                    return true;
                // If no valid sequence found delete the last added number and continue the search.
                isVisited.erase(next);
                ret.pop_back();
            }
        }
        return false;
    }
};