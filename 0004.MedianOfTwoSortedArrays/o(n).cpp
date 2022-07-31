class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int len1 = v1.size(), len2 = v2.size(), mid = (len1 + len2) / 2;
        int p1 = 0, p2 = 0, cur = 0, last = 0;
        // 0~7. lem:8 mid:4
        for(int i = 0; i < mid + 1; ++i){
            last = cur;
            if(p1 < len1 && p2 < len2){
                if(v1[p1] < v2[p2]){
                    cur = v1[p1];
                    p1++;
                }else{
                    cur = v2[p2];
                    p2++;
                }
            }else if(p1 < len1){
                cur = v1[p1];
                p1++;
            }else{
                //p2 < len2
                cur = v2[p2];
                p2++;
            }
        }
        // cout << "p1:" << p1 << ",p2:" << p2 << endl;
        if((len1 + len2) % 2 == 0){
            return ((double)(last + cur)) / 2;
        }else{
            return (double) cur;
        }
        
    }
};