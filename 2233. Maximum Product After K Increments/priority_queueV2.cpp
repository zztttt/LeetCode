class Solution {
public:
    int maximumProduct(vector<int>& v, int k) {
        auto comparator = [](int n1, int n2){
            return n1 > n2;
        };
        priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);
        
        for(int i: v){
            heap.push(i);
        }
        
        for(int i = 0; i < k; ++i){
            int ele = heap.top();
            heap.pop();
            heap.push(ele + 1);
        }
        
        long long ret = 1, mod = pow(10, 9) + 7;
        while(!heap.empty()){
            ret = (ret * heap.top()) % mod;
            heap.pop();
        }
        return ret;
    }
};