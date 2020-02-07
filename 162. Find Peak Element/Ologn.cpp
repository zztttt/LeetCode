class Solution {
public:
    int findPeakElement(vector<int>& v) {
        if(v.size() == 0 )
            return -1;
        if(v.size() == 1)
            return 0;
        int len = v.size(), low = 0, high = len - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(v[mid] < v[mid + 1]){
                low = mid + 1;
            }else if(v[mid] >= v[mid + 1]){
                high = mid;
            }
        }
        return low;
    }
};