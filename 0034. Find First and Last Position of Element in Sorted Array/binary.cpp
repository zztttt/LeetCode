class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int low = 0, high = v.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(v[mid] == target){
                return spread(v, mid, mid, target);
            }else if(v[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
    
    vector<int> spread(const vector<int>& v, int low, int high, int target){
        while(low >= 0){
            if(v[low] == target){
                low--;
            }else{
                break;
            }
        }
        while(high < v.size()){
            if(v[high] == target){
                high++;
            }else{
                break;
            }
        }
        
        return {low + 1, high - 1};
    }
};