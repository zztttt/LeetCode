class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int len1 = v1.size(), len2 = v2.size();
        int mid = (len1 + len2) / 2, p1 = 0, p2 = 0, last = -1, cur = -1;;
        
        double ret;
        bool isEven = (len1 + len2)%2 == 0;
        // 3: mid = 1, v[1]
        // 4: mid = 2, (v[1] + v[2])/2 
        for(int i = 0; i <= mid; ++i){
            last = cur;
            if(p1 < len1 && p2 < len2){
                int cur1 = v1[p1], cur2 = v2[p2];
                if(cur1 > cur2){
                    cur = v2[p2++];
                }else{
                    cur = v1[p1++];
                }
            }else if(p1 < len1){
                // v2 is full
                cur = v1[p1++];
            }else if(p2 < len2){
                cur = v2[p2++];
            }else
                assert(0);
            //cout << "last:" << last << ", cur:" << cur << endl;
        }
        //cout << "p1:" << p1 << ", p2:" << p2 << endl;
        
        if(isEven){
            ret = (last + cur) / 2.0;
        }else{
            ret = cur;
        }

        return ret;
    }
};