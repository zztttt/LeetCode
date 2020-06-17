class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int low = 1, high = x;
        while( low <= high){
            //int mid = (low + high) / 2;
            int mid = low + (high - low) / 2;
            if(mid > x / mid)
                high = mid - 1;
            else if(mid < x / mid)
                low = mid + 1;
            else
                return mid;
        }
        return high;
    }
};