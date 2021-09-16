class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size(), ret = 1, start = 0;
        if(len == 0)
            return 0;
        for(int i = 0; i < len - 1; ++i){
            if(i % 2 == 0){
                // even
                if(arr[i] > arr[i + 1]){
                    // valid
                    ret = max(i - start + 2, ret);
                }else{
                    start = i + 1;
                }
            }else{
                // odd
                if(arr[i] < arr[i + 1]){
                    // valid
                    ret = max(i - start + 2, ret);
                }else{
                    start = i + 1;
                }
            }
        }
        start = 0;
        for(int i = 0; i < len - 1; ++i){
            if(i % 2 == 0){
                // even
                if(arr[i] < arr[i + 1]){
                    // valid
                    ret = max(i - start + 2, ret);
                }else{
                    start = i + 1;
                }
            }else{
                // odd
                if(arr[i] > arr[i + 1]){
                    // valid
                    ret = max(i - start + 2, ret);
                }else{
                    start = i + 1;
                }
            }
        }
        return ret;
    }
};