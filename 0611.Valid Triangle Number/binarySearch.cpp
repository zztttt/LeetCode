class Solution {
public:
    int triangleNumber(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = v.size(), ret = 0;
        for(int i = 0; i < len - 2; ++i){
            int k = i + 2;
            for(int j = i + 1; j < len - 1 && v[i] != 0; ++j){
                int index = searchIndex(v, k, len - 1, v[i] + v[j]);
                //cout << "index:" << index << endl;
                ret =  ret + index - j -1;
            }
        }
        return ret;
    }
    // find i, for which element v[i] >= target
    int searchIndex(vector<int>& v, int low, int high, int target){
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(v[mid] < target){
                low = mid + 1;
            }else if(v[mid] >= target){
                high = mid - 1;
            }
        }
        return low;
    }
};