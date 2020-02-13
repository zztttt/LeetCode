class Solution {
public:
    int maxArea(vector<int>& h) {
        if(h.size() == 0) return 0;
        int len = h.size(), low = 0, high = len - 1, ret = 0;
        while(low < high){
            int curWeight = min(h[low], h[high]) * (high - low);
            ret = max(ret, curWeight);
            if(h[low] > h[high]){
                high--;
            }else{
                low++;
            }
        }

        return ret;
    }
};