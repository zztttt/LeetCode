class Solution {
public:
    set<int> st;
    bool isHappy(int n) {
        int res = cal(n);
        if(st.find(res) != st.end())
            return false;
        else if(res == 1)
            return true;
        else
            st.insert(res);
        return isHappy(res);
        
    }
    int cal(int n){
        int ret = 0;
        while(n != 0){
            int pop = n % 10;
            n = n / 10;
            ret += pop * pop;
        }
        return ret;
    }
};