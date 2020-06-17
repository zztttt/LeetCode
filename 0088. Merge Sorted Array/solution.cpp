class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1;
        for(int i = m + n -1; i >= 0; --i){
            int tmp;
            if(pos1 >= 0 && pos2 >= 0){
                if(nums1[pos1] > nums2[pos2]){
                    tmp = nums1[pos1];
                    pos1--;
                }else{
                    tmp = nums2[pos2];
                    pos2--;
                }
            }else if(pos1 >= 0){
                tmp = nums1[pos1];
                pos1--;
            }else if(pos2 >= 0){
                tmp = nums2[pos2];
                pos2--;
            }
            
            nums1[i] = tmp;
        }
    }
};