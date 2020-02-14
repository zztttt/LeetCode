class Solution {
public:
    int search(vector<int>& v, int target) {
        if(v.size() == 0) 
            return -1;
        int len = v.size(), low = 0, high = len - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            // cout << "low:" << low << ", high:" << high << ", mid:" << mid << endl;
            int cur = v[mid];
            if(cur == target){
                return mid;
            }else if(cur < target){
                // mid in the original part
                if(cur >= v[low]){
                    low = mid + 1;
                }else{
                    // mid in the rotated part
                    if(target > v[high]){
                        // target in the original part
                        high = mid - 1;
                    }else{
                        // target in the rotated part
                        low = mid + 1;
                    }
                }
            }else if(cur > target){
                // mid in the rotated part
                if(cur <= v[high]){
                    high = mid - 1;
                }else{
                    // mid in the original part
                    if(target >= v[low]){
                        // target in the original part
                        high = mid - 1;
                    }else{
                        // target in the rotated part
                        low = mid + 1;
                    }
                }
            }
        }

         return -1;
    }
};