class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(const char& c: s){
            if(stk.empty()){
                stk.push(c);
                continue;
            }
            if(isMatching(stk.top(), c)){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        
        return stk.size() == 0;
    }
    
    bool isMatching(const char& c1, const char& c2){
        switch(c1){
            case '(': return c2 == ')';
            case '[': return c2 == ']';
            case '{': return c2 == '}';
        }
        return false;
    }
};