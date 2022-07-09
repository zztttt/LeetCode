class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int len = v.size();
        deque<int> index;
        vector<int> ret(len - k + 1, 0);
        int offset = 0;
        
        for(int i = 0; i < len; ++i){
            // our of range
            while(!index.empty() && index.front() < i - k + 1) {
                index.pop_front();
            }
            // update monoqueue
            while(!index.empty() && v[index.back()] < v[i]){
                index.pop_back();
            }
            // update index
            index.push_back(i);
            // update ret
            if (i >= k - 1) {
                ret[offset++] = v[index.front()];
            }
        }
        return ret;
    }
};