class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        // move towards right
        for(int i = m - 1; i >= 0; --i){
            v1[i + n] = v1[i];
        }
        int pos1 = n, pos2 = 0, index = 0;
        while(index < m + n){
            int a = pos1 < m + n? v1[pos1]:INT_MAX;
            int b = pos2 < n? v2[pos2]:INT_MAX;
            if(a < b){
                v1[index++] = a;
                pos1++;
            }else{
                v1[index++] = b;
                pos2++;
            }
        }
    }
};