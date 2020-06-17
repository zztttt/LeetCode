class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int len = intervals.size();
        if(len == 0) return ret;
        
        // sort by first val
        sort(intervals.begin(), intervals.end(), cmp);
        // init
        ret.push_back(intervals[0]);
        // update
        for(int i = 1; i < len; ++i){
            vector<int> cur = intervals[i];
            vector<int> last = ret.back();
            // cur.start > last.end
            if(cur[0] > last[1]){
                ret.push_back(cur);
            }else{
                // update end
                int end = max(cur[1], last[1]);
                ret[ret.size() - 1][1] = end;
            }
        }
        return ret;
        
    }
    
    // comparator
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
};