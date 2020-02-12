class Solution {
public:
    bool isPowerOfThree(int n) {
        //3**19 / 27 = 3**19 / 3**3 = 3**16
        //Meaning: 3**19 % 27 == 3**19 % 3**3 == 0
        return n > 0 && !(1162261467 % n);
    }
};