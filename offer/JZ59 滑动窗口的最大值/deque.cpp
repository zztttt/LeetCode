class Solution {
public:
    vector<int> maxInWindows(const vector<int>& v, unsigned int size) {
        int len = v.size();
        vector<int> ret;
        deque<int> index;
        for(int i = 0; i < len; ++i){
            while(index.size() > 0 && v[index.back()] < v[i]){
                index.pop_back();
            }
            // v[i] > back
            index.push_back(i);
            if(i - index.front() >= size)
                index.pop_front();
            if(i >= size - 1)
                ret.push_back(v[index.front()]);
        }
        return ret;
    }
};