class Solution {
public:
    int maxResult(vector<int>& v, int k) {
        int len = v.size();
        deque<int> index;
        map<int, int> next;
        
        for(int i = 0; i < len; ++i){
            // carry the value
            int max = index.empty()? 0 : v[index.front()];
            v[i] = v[i] + max;
            
            // remove out of date
            while(!index.empty() && index.front() < i - k + 1){
                index.pop_front();
            }
            
            // remove useless index
            while(!index.empty() && v[index.back()] < v[i]){
                index.pop_back();
            }
            
            // update index
            index.push_back(i);
        }
        
        return v[len - 1];
    }
};