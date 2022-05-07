class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int len = v.size();
        stack<int> stk;
        vector<int> index;
        
        int right = INT_MIN;
        for(int i = len - 1; i >= 0; --i){
            int cur = v[i];
            if(cur < right)
                return true;
            
            while(!stk.empty() && cur > stk.top()){
                right = stk.top();
                stk.pop();
            }
            stk.push(cur);
        }
        return false;
    }
};