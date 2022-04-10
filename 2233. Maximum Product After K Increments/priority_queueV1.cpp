class Solution {
public:
    //[24,5,64,53,26,38] 54
    int maximumProduct(vector<int>& v, int k) {
        map<int, int> freq;
        for(int i: v){
            freq[i] += 1;
        }
        
        auto comparator = [](int n1, int n2){
            return n1 > n2;
        };
        
        priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);
        for(map<int, int>::iterator it = freq.begin(); it != freq.end(); it++){
            //cout << it->first << "," << it->second << endl;
            heap.push(it->first);
        }
        
        for(int i = 0; i < k; ++i){
            int ele = heap.top();
            freq[ele]--;
            if(freq[ele] == 0){
                freq.erase(ele);
                heap.pop();
                //cout << "erase:" << ele << endl;
            }
            if(freq[ele + 1] == 0){
                freq[ele + 1] = 1;
                heap.push(ele + 1);
                //cout << "new ele:" << ele + 1 << endl;
            }else{
                freq[ele + 1]++;
            }
            //printM(freq);
        }
        
        long long ret = 1, mod = pow(10, 9) + 7;
        while(!heap.empty()){
            int ele = heap.top();
            ret = (ret * ele) % mod;
            freq[ele]--;
            if(freq[ele] == 0){
                heap.pop();
            }
        }
        return ret;
    }
    void printM(map<int, int>& freq){
        for(map<int, int>::iterator it = freq.begin(); it != freq.end(); it++){
            cout << it->first << "," << it->second << " | ";
        }
        cout << endl;
    }
};