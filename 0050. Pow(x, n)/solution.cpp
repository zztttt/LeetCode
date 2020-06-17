class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        int mid = n / 2;
        int rest = n % 2;
        if(rest == 0){
            double half = myPow(x, mid);
            return half * half;
        }else{
            double half = myPow(x, mid);
            if(rest > 0) return half * half * x;
            else return half * half / x;
        }
    }
};