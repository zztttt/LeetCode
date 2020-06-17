class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
            return 0;
        int five = 0;
        while(n > 0){
            five = five + n / 5;
            n = n / 5;
        }
        return five;
    }
};