class Solution {
public:
    // 4k+3
    bool canWinNim(int n) {
        if(n % 4 == 0)
            return false;
        return true;
    }
};