class Solution {
public:
    vector<int> grayCode(int n) {
        if(n < 0)
            return {};
        if(n == 0)
            return vector<int>(1, 0);
        
        // 00 01 11 10
        // 000 001 011 010 + 110 111 101 100
        vector<int> last = grayCode(n - 1);
        vector<int> ret(last);
        int len = last.size(), prefix = 1 << (n - 1);
        for(int i = len - 1; i >= 0; --i){
            ret.push_back(last[i] + prefix);
        }

        return ret;
    }
};