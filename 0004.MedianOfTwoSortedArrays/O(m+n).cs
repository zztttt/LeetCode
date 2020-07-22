public class Solution {
    public double FindMedianSortedArrays(int[] v1, int[] v2) {
        int len1 = v1.Length, len2 = v2.Length;
        int mid = (len1 + len2) / 2, p1 = 0, p2 = 0, last = -1, cur = -1;
        double ret;
        bool isEven = (len1 + len2) % 2 == 0;
        /*
        * len = 3. mid:1, ret: v[1]
        * len = 4. mid:2, ret: (v[1] + v[2])/2
        */
        for(int i = 0; i <= mid; ++i){
            last = cur;
            // both not full
            if(p1 < len1 && p2 < len2){
                int a = v1[p1], b = v2[p2];
                if(a < b){
                    cur = a;
                    p1++;
                }else{
                    cur = b;
                    p2++;
                }
            }else if(p1 < len1){
                // v1 is not full
                cur = v1[p1];
                p1++;
            }else{
                // v2 is not full
                cur = v2[p2];
                p2++;
            }
        }
        if(isEven){
            return (double)(last + cur) / 2;
        }else{
            return (double)cur;
        }
    }
}