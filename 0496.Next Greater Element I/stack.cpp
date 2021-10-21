class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> m;
        vector<int> ret;
        
        for(const int& n: nums2){
            while(stk.size() > 0 && stk.top() < n){
                m[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        }
        
        for(const int& n: nums1){
            if(m.find(n) != m.end())
                ret.push_back(m[n]);
            else
                ret.push_back(-1);
        }
        
        return ret;
    }
};