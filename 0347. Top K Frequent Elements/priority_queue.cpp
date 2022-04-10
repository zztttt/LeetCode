class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int, int> freq;
        for(const int& i: v){
            freq[i] += 1;
        }
        
        auto comparator = [&freq](int n1, int n2) {
            return freq[n1] > freq[n2];
        };
        priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);
        
        for(map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it){
            heap.push(it->first);
            if(heap.size() > k){
                heap.pop();
            }
        }
        
        vector<int> ret;
        while(!heap.empty()){
            ret.push_back(heap.top());
            heap.pop();
        }
        return ret;
    }
};