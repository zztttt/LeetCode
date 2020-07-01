class Solution {
public:
    int search(vector<int>& v, int target) {
        if(v.size() == 0)
            return -1;
        int len = v.size(), low = 0, high = len - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int cur = v[mid];
            if(cur == target){
                return mid;
            }else if(target < cur){
                if(cur <= v[high]){
                    high = mid - 1;
                }else{
                    if(target >= v[low]){
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                }
            }else{
                // target > cur
                if(cur >= v[low]){
                    low = mid + 1;
                }else{
                    if(target <= v[high]){
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};