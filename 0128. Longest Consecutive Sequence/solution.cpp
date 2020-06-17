class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        set<int> s;
        for(int tmp: nums){
            s.insert(tmp);
        }
        
        int ret = 0;
        for(int tmp: nums){
            if(s.find(tmp) != s.end()){
                int left = tmp - 1, right = tmp + 1, localMax = 1;
                
                set<int>::iterator leftIt, rightIt;
                while((leftIt = s.find(left)) != s.end()){
                    left--;
                    localMax++;
                    s.erase(leftIt);
                }
                while((rightIt = s.find(right)) != s.end()){
                    right++;
                    localMax++;
                    s.erase(rightIt);
                }
                ret = max(ret, localMax);
            }else{
                
            }
        }
        
        return ret;
    }
};