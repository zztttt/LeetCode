class Solution {
public:
    string func(string s){
        int len = s.size();
        stack<char> stk;
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(cur == '#'){
                if(!stk.empty())
                    stk.pop();
            }else
                stk.push(cur);
        }
        string ret = "";
        while(!stk.empty()){
            char c = stk.top();
            stk.pop();
            ret = c + ret;
        }
        return ret;
    }
    bool backspaceCompare(string S, string T) {
        return func(S) == func(T);
    }
};