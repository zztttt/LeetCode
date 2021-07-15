class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int len = v.size(), low = 0, high = len - 1;
        while(low < high){
            int mid = (high - low) / 2 + low;
            if(v[mid] < v[mid + 1]){
                low = mid + 1;
            }else if(v[mid] >    v[mid + 1]){
                high = mid;
            }
        }
        return low;
    }
};