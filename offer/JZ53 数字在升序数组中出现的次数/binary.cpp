class Solution {
public:
    int get(const vector<int> v, int index, int k){
        int len = v.size(), low = index - 1, high = index + 1, ret = 1;
        while(low >= 0){
            if(v[low] == k)
                ret++;
            low--;
        }
        while(high <= len - 1){
            if(v[high] == k)
                ret++;
            high++;
        }
        return ret;
    }
    
    int GetNumberOfK(vector<int> v,int k) {
        int len = v.size(), low = 0, high = len - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cur = v[mid];
            if(cur == k){
                return get(v, mid, k);
            }else if(k < cur){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return 0;
    }
};