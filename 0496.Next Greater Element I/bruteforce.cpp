class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len2 = nums2.size();
        unordered_map<int, int> index;
        for(int i = 0; i < len2; ++i){
            index[nums2[i]] = i;
        }

        // for(unordered_map<int, int>::iterator it = index.begin(); it != index.end(); it++){
        //     cout << "key:" << it->first << ", index:" << it->second << endl;
        // }
        
        vector<int> ret;
        for(const int& n: nums1){
            int minPos = index[n] + 1;
            bool isFound = false;
            for(int i = minPos; i < len2; ++i){
                if(nums2[i] > n){
                    ret.push_back(nums2[i]);
                    isFound = true;
                    break;
                }
            }
            
            if(!isFound)
                ret.push_back(-1);
        }
        
        return ret;
    }
};