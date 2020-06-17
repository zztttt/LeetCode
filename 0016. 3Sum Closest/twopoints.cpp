class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), ret = INT_MIN, gap = INT_MAX;
        sort(v.begin(), v.end());

        for(int i = 0; i < len - 2; ++i){
            if(i > 0 && v[i] == v[i - 1])
                continue;
            
            int left = i + 1, right = len - 1, t = target - v[i];
            while(left < right){
                int curGap = abs(t - v[left] - v[right]);
                if(curGap < gap){
                    gap = curGap;
                    ret = v[i] + v[left] + v[right];
                }
                if(v[left] + v[right] <= t){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return ret;
    }
};