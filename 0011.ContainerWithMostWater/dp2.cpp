class Solution {
public:
    int maxArea(vector<int>& h) {
        int len = h.size(), low = 0, high = len - 1, ret = 0;
        while(low < high){
            int height = min(h[low], h[high]);
            ret = max(ret, (high - low) * height);
            if(h[high] > h[low]){
                low++;
            }else{
                high--;
            }
        }
        return ret;
    }
};