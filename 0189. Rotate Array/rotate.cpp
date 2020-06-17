class Solution {
public:
    void rotate(vector<int>& v, int k) {
        for(int i = 0; i < k; ++i){
            int tail = v.back();
            v.insert(v.begin(), tail);
            v.pop_back();
        }
    }
};